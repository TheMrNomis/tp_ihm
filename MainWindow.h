#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QFileDialog>
#include <QErrorMessage>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QAction>
#include <QIcon>

#include "GraphicsImageScene.h"
#include "GraphicsImageView.h"

#include "scale/ScaleModel.h"
#include "scale/ScalePresenter.h"
#include "scale/ScaleParameterWidget.h"

#include "inpainting/InpaintingModel.h"
#include "inpainting/InpaintingPresenter.h"
#include "inpainting/InpaintingParameterWidget.h"

#include "rotation/RotationModel.h"
#include "rotation/RotationPresenter.h"
#include "rotation/RotationParameterWidget.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  void setupGUI();
  void setupMenuBar();

private slots:
  void loadImage();
  void saveImage();

private:
  QErrorMessage * m_errorMessages;

  //central widget stuff
  QWidget * m_centralWidget;

  GraphicsImageScene * m_inputScene;
  GraphicsImageScene * m_resultScene;

  GraphicsImageView * m_inputView;
  GraphicsImageView * m_resultView;

  QTabWidget * m_parameterContainer;

  //scale stuff
  ScaleParameterWidget * m_scaleParameterWidget;
  ScaleModel * m_scaleModel;
  ScalePresenter * m_scalePresenter;

  //inpainting stuff
  InpaintingParameterWidget * m_inpaintingParameterWidget;
  InpaintingModel * m_inpaintingModel;
  InpaintingPresenter * m_inpaintingPresenter;

  //rotation stuff
  RotationParameterWidget * m_rotationParameterWidget;
  RotationModel * m_rotationModel;
  RotationPresenter * m_rotationPresenter;

  //menubar actions
  QAction * m_quitAction;
  QAction * m_openImageAction;
  QAction * m_saveImageAction;
};

#endif // MAINWINDOW_H
