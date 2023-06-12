QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    edge.cpp \
    graph.cpp \
    main.cpp \
    priority.cpp \
    vertex.cpp

HEADERS += \
    edge.h \
    graph.h \
    priority.h \
    vertex.h

FORMS += \
    graph.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    Grafs.pro

DISTFILES += \
    Grafs.pro.user \
    komi_work.pro.user
