
QT += widgets network sql

TARGET = YourApplicationName
TEMPLATE = app

SOURCES += \
    adminDB.cpp \
    main.cpp \
    login.cpp \
    Formulario.cpp

HEADERS += \
    adminDB.h \
    login.h \
    Formulario.h


RESOURCES +=

LIBS +=

# Configuración de la API de OpenWeatherMap
DEFINES += OPENWEATHERMAP_API_KEY="23452d788ca74ae5acd154411241604"
