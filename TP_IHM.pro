#-------------------------------------------------
#
# Project created by QtCreator 2015-11-24T14:13:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TP_IHM
TEMPLATE = app

CONFIG += c++14
LIBS += -lvisp


SOURCES += main.cpp\
        MainWindow.cpp \
    AbstractModel.cpp \
    AbstractPresenter.cpp \
    AbstractParameterWidget.cpp \
    scale/ScaleModel.cpp \
    GraphicsImageView.cpp \
    GraphicsImageScene.cpp \
    scale/ScalePresenter.cpp \
    scale/ScaleParameterWidget.cpp \
    DrawableGraphicsScene.cpp \
    inpainting/InpaintingModel.cpp \
    inpainting/InpaintingParameterWidget.cpp \
    inpainting/InpaintingPresenter.cpp \
    rotation/RotationModel.cpp \
    rotation/RotationParameterWidget.cpp \
    rotation/RotationPresenter.cpp

HEADERS  += MainWindow.h \
    AbstractModel.h \
    AbstractPresenter.h \
    AbstractParameterWidget.h \
    scale/ScaleModel.h \
    GraphicsImageView.h \
    GraphicsImageScene.h \
    scale/ScalePresenter.h \
    scale/ScaleParameterWidget.h \
    ImageConverter.h \
    rotation/RotationModel.h \
    rotation/RotationParameterWidget.h \
    rotation/RotationPresenter.h \
    DrawableGraphicsScene.h \
    inpainting/InpaintingModel.h \
    inpainting/InpaintingParameterWidget.h \
    inpainting/InpaintingPresenter.h

DISTFILES +=

RESOURCES += \
    images/GUI.qrc
