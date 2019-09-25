#-------------------------------------------------
#
# Project created by QtCreator 2019-08-27T12:58:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SortCompare
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        bubble.cpp \
        composefile.cpp \
        countingsort.cpp \
        dfs.cpp \
        heapsort.cpp \
        insertionsort.cpp \
        login.cpp \
        main.cpp \
        mainwindow.cpp \
        map.cpp \
        mergesort.cpp \
        node.cpp \
        quicksort.cpp \
        radixsort.cpp \
        sortshow.cpp \
        tspandbbalgorithm.cpp \
        tspanddfs.cpp \
        tspdialog.cpp \
        usercode.cpp \
        writecode.cpp \
        ww_tsp_bfs.cpp

HEADERS += \
        bubble.h \
        composefile.h \
        countingsort.h \
        dfs.h \
        heapsort.h \
        insertionsort.h \
        login.h \
        mainwindow.h \
        map.h \
        mergesort.h \
        node.h \
        quicksort.h \
        radixsort.h \
        sortshow.h \
        tspandbbalgorithm.h \
        tspanddfs.h \
        tspdialog.h \
        usercode.h \
        writecode.h \
        ww_tsp_bfs.h

FORMS += \
        login.ui \
        mainwindow.ui \
        sortshow.ui \
        tspanddfs.ui \
        tspdialog.ui \
        usercode.ui \
        writecode.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    srcouse.qrc
