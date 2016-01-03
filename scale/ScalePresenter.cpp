#include "ScalePresenter.h"

#include <QDebug>

ScalePresenter::ScalePresenter(MainWindow* parent, ScaleModel* model, ScaleParameterWidget* parametersWidget, GraphicsImageScene* inputScene, GraphicsImageScene* resultScene):
  AbstractPresenter(parent, model, parametersWidget, inputScene, resultScene),
  m_scaleModel(model),
  m_scaleParameterWidget(parametersWidget)
{

}


void ScalePresenter::runModel()
{
  m_scaleModel->setInput(ImageConverter::qImageToVpImageRGBA(m_inputScene->image()));
  m_scaleModel->setScaleFactor(m_scaleParameterWidget->getFactor());
  m_scaleModel->run();
}

void ScalePresenter::presentModelResults()
{
  m_resultScene->setImage(ImageConverter::vpImageRGBAToQImage(m_scaleModel->output()));
}
