QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    src/main.cpp \
    src/resourse/Console.cpp \
    src/resourse/MianService.cpp \
    src/window/MainWidget.cpp \
    src/window/backstage.cpp \
    src/window/manage.cpp \
    src/window/navigation.cpp \
    src/window/packetinfo.cpp \
    src/window/sign.cpp \

HEADERS += \
    header/Basic.h \
    header/console.h \
    header/main.h \
    header/mainService.h \
    header/packet.h \
    header/user.h \
    header/window/mainwidget.h \
    header/window/navigation.h \
    header/window/packetinfo.h \
    header/window/backstage.h \
    header/window/signin.h \
    header/window/manage.h

FORMS += \
    ui/manage.ui \
    ui/backstage.ui \
    ui/packetinfo.ui \
    ui/navigation.ui \
    ui/mainwidget.ui \
    ui/signin.ui \

LIBS += -lws2_32

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
  res.qrc
