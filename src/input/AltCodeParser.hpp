#pragma once
#include <QString>
#include <QMap>

class AltCodeParser
{
private:
    QMap<QString, QString> m_codeMap;
public:
    AltCodeParser() = default;

    // Loads the codes from a JSON and adds them to the map
    bool loadFromFile(const QString& filePath);

    // Returns the corresponding character for an alt code combination
    QString getCharacter(const QString& code) const;
};
