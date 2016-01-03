#include "AbstractPresenter.h"

AbstractPresenter::AbstractPresenter(MainWindow* parent, AbstractModel* model, AbstractParameterWidget* parameterWidget, GraphicsImageScene* inputScene, GraphicsImageScene* resultScene) :
  m_parent(parent),
  m_model(model),
  m_parameterWidget(parameterWidget),
  m_inputScene(inputScene),
  m_resultScene(resultScene)
{
    QObject::connect(m_parameterWidget, SIGNAL(runRequest()), this, SLOT(runModel()));
    QObject::connect(m_model, SIGNAL(success()), this, SLOT(presentModelResults()));
}

