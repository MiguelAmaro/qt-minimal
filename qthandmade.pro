QT += core gui widgets

VPATH += src

HEADERS += \
    calc.h \
    button.h \

SOURCES += \
    main.cpp \
    calc.cpp \
    button.cpp

# DESTDIR = $$PWD/build

target.path = $$PWD/build
INSTALLS += target
