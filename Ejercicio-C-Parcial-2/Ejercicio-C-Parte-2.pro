QT += sql network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
HEADERS += \
    AdminDB.h \
    Login.h \
    Manager.h \
    Ventana.h

SOURCES += \
    AdminDB.cpp \
    Login.cpp \
    Manager.cpp \
    Ventana.cpp \
    main.cpp

FORMS += \
    Login.ui \
    Ventana.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
