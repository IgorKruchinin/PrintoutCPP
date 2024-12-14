QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -lsqlite3

SOURCES += \
    excelmanager.cpp \
    main.cpp \
    printoutmainwin.cpp \
    printouttabledialog.cpp \
    api/db/Dao.cpp

HEADERS += \
    excelmanager.h \
    printQt.h \
    printoutmainwin.h \
    printouttabledialog.h \
    api/Printout.h \
    api/Record.h \
    api/Definitions.h \
    api/Printer.h \
    api/TableStructure.h \
    api/db/Dao.h \
    api/excelManager/excelManager.h

FORMS += \
    printoutmainwin.ui \
    printouttabledialog.ui

TRANSLATIONS += \
    Printout_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
