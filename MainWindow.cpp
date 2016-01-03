#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent),
    m_errorMessages(new QErrorMessage(this)),
    m_centralWidget(new QWidget(this)),

    m_inputScene(new GraphicsImageScene(this)),
    m_resultScene(new GraphicsImageScene(this)),
    m_inputView(new GraphicsImageView(m_inputScene, m_centralWidget)),
    m_resultView(new GraphicsImageView(m_resultScene, m_centralWidget)),

    m_parameterContainer(new QTabWidget(this)),

    m_scaleParameterWidget(new ScaleParameterWidget(m_parameterContainer)),
    m_scaleModel(new ScaleModel),
    m_scalePresenter(new ScalePresenter(this, m_scaleModel, m_scaleParameterWidget, m_inputScene, m_resultScene)),

    m_rotationParameterWidget(new RotationParameterWidget(m_parameterContainer)),
    m_rotationModel(new RotationModel),
    m_rotationPresenter(new RotationPresenter(this, m_rotationModel, m_rotationParameterWidget, m_inputScene, m_resultScene)),

    m_quitAction(new QAction(QIcon::fromTheme("application-exit"), "quit", this)),
    m_openImageAction(new QAction(QIcon::fromTheme("document-open"), "open", this)),
    m_saveImageAction(new QAction(QIcon::fromTheme("document-save"), "save", this))
{
  setupGUI();
  setupMenuBar();
}

MainWindow::~MainWindow()
{

}

void MainWindow::setupGUI()
{
  QVBoxLayout * graphicsViewLayout = new QVBoxLayout;
  graphicsViewLayout->addWidget(m_inputView);
  graphicsViewLayout->addWidget(m_resultView);

  QHBoxLayout * mainLayout = new QHBoxLayout(m_centralWidget);
  this->setCentralWidget(m_centralWidget);

  mainLayout->addWidget(m_parameterContainer);
  mainLayout->addLayout(graphicsViewLayout);

  //scaling
  m_parameterContainer->addTab(m_scaleParameterWidget, m_scaleParameterWidget->title());

  //rotation
  m_parameterContainer->addTab(m_rotationParameterWidget, m_rotationParameterWidget->title());
}

void MainWindow::setupMenuBar()
{
  QObject::connect(m_openImageAction, SIGNAL(triggered()), this, SLOT(loadImage()));
  QObject::connect(m_saveImageAction, SIGNAL(triggered()), this, SLOT(saveImage()));
  QObject::connect(m_quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

  QMenu * fileMenu = menuBar()->addMenu(tr("&File"));
  fileMenu->addAction(m_openImageAction);
  fileMenu->addAction(m_saveImageAction);
  fileMenu->addSeparator();
  fileMenu->addAction(m_quitAction);
}

void MainWindow::loadImage()
{
  QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::homePath(), tr("Image Files(*.png *.jpg *.bmp *.pgm *.ppm);;All files(*)"));
  if(filename != "")
  {
      QImage img(filename);

      m_inputScene->setImage(img);
  }
}

void MainWindow::saveImage()
{
  QString filename = QFileDialog::getSaveFileName(this, tr("Save Image"), QDir::homePath()+QString("/result.png"), tr("Images Files(*.png *.jpg *.bmp);;All files(*)"));
  if(filename != "")
  {
    bool saveState = m_resultView->scene()->image().save(filename);
    if(!saveState)
      m_errorMessages->showMessage(tr("Error while saving the file (sorry, no more information available)"));
  }
}
