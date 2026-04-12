#include "AltCodeParser.hpp"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

bool AltCodeParser::loadFromFile(const QString& filePath) {
    QFile file(filePath);

    // Try to open the file
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qWarning() << "Could not open the JSON file: " << filePath;
        return false;
    }

    // Get the raw data, parse the the JSON
    QByteArray rawData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(rawData, &parseError);

    if (doc.isNull()) {
        qWarning() << "JSON parse error: " << parseError.errorString();
        return false;
    }

    // Extract the "code" side of the object
    QJsonObject root = doc.object();
    if (!root.contains("codes") || !root["codes"].isObject()) {
        qWarning() << "JSON does not contain a valid 'codes' object";
        return false;
    }

    QJsonObject codes = root["codes"].toObject();

    // Populate the internal Map
    // User profile will override default if it exists
    for (auto it = codes.begin(); it != codes.end(); ++it) {
        m_codeMap.insert(it.key(), it.value().toString());
    }

    qInfo() << "Successfully loaded " << m_codeMap.size() << "Alt-codes from " << filePath;
    return true;
}

QString AltCodeParser::getCharacter(const QString& code) const {
    // Returns an empty QString if the code isn't present in the map
    return m_codeMap.value(code, "");
}