
QT += widgets network

TARGET = YourApplicationName
TEMPLATE = app

SOURCES += \
    main.cpp \
    login.cpp \
    Formulario.cpp

HEADERS += \
    login.h \
    Formulario.h


RESOURCES +=

LIBS +=

# Configuración de la API de OpenWeatherMap
DEFINES += OPENWEATHERMAP_API_KEY="23452d788ca74ae5acd154411241604"
