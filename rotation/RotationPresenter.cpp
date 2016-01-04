#include "RotationPresenter.h"

RotationPresenter::RotationPresenter(MainWindow* parent, RotationModel* model, RotationParameterWidget* parametersWidget, GraphicsImageScene* inputScene, GraphicsImageScene* resultScene):
  AbstractPresenter(parent, model, parametersWidget, inputScene, resultScene),
  m_rotationModel(model),
  m_rotationParameterWidget(parametersWidget)
{

}

void RotationPresenter::runModel()
{
  m_rotationModel->setInput(ImageConverter::qImageToVpImageRGBA(m_inputScene->image()));
  m_rotationModel->setAngle(m_rotationParameterWidget->getAngle());
  m_rotationModel->run();
}

void RotationPresenter::presentModelResults()
{
  m_resultScene->setImage(ImageConverter::vpImageRGBAToQImage(m_rotationModel->output()));
}
