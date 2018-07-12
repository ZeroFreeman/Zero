TEMPLATE = app

CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L../lib/x86 -lSDL2
LIBS += -L../lib/x86 -lSDL2main
LIBS += -L../lib/x86 -lSDL2test

LIBS += -L../SDL2_image-2.0.3/lib/x86 -lSDL2_image

SOURCES += main.cpp
