QT       += core gui

TARGET = CardCreator
TEMPLATE = app


SOURCES += main.cpp\
        WindowMain.cpp \
    Card.cpp \
    ColorPreview.cpp \
    CardConfig.cpp \
    Item.cpp

HEADERS  += WindowMain.h \
    Card.h \
    ColorPreview.h \
    Item.h \
    CardConfig.h

FORMS    += WindowMain.ui
