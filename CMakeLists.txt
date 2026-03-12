cmake_minimum_required(VERSION 3.21)
project(AltType VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

file(GLOB_RECURSE ALL_SRCS 
    "src/*.cpp"
    "src/*.hpp"
)

add_executable(${PROJECT_NAME} ${ALL_SRCS})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)

set_target_properties(${PROJECT_NAME} PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES packaging/alttype.desktop DESTINATION ${CMAKE_INSTALL_DATADIR}/applications)
install(FILES data/alt-codes.json DESTINATION ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME})

include(CTest)
enable_testing()

