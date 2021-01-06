TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt
CONFIG += testcase

QT += testlib
QT += gui
QT += core
QT += widgets

INCLUDEPATH += ..\EuroToDollarCalculatorApplication\x64\Debug\uic

HEADERS += \
    EuroToDollarCalculatorApplicationTest.h \
    EuroToDollarCalculatorApplicationTest.h \
    Mockeuro_to_dollar_presenter.h

HEADERS += \
    ..\EuroToDollarCalculatorApplication\EuroToDollarCalculatorApplication.h

SOURCES += \
        EuroToDollarCalculatorApplicationTest.cpp \
        main.cpp

LIBS += ..\EuroToDollarCalculatorApplication\x64\Debug\EuroToDollarCalculatorApplication.obj

#LIBS += C:\Users\JoachimWagner\source\repos\EuroToDollarCalculatorApplication\EuroToDollarCalculatorApplication\x64\Debug\qrc_EuroToDollarCalculatorApplication.obj



include(gtest_dependency.pri)
