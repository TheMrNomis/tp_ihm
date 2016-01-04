#include "InpaintingPresenter.h"

InpaintingPresenter::InpaintingPresenter(MainWindow * parent, InpaintingModel * model, InpaintingParameterWidget * parameterWidget, GraphicsImageScene * inputScene, GraphicsImageScene * resultScene):
  AbstractPresenter(parent, model, parameterWidget, inputScene, resultScene),
  m_inpaintingModel(model)
{

}

void InpaintingPresenter::runModel()
{
  m_inpaintingModel->setInput(ImageConverter::qImageToVpImageRGBA(m_inputScene->image()));
  m_inpaintingModel->setMask(ImageConverter::qImageToVpImageUCHAR(m_inputScene->mask()));
  m_inpaintingModel->run();
}

void InpaintingPresenter::presentModelResults()
{
  m_resultScene->setImage(ImageConverter::vpImageRGBAToQImage(m_inpaintingModel->output()));
}
