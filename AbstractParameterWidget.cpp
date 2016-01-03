#include "AbstractParameterWidget.h"

AbstractParameterWidget::AbstractParameterWidget(QString const& title, QWidget *parent) :
  QWidget(parent),
  m_parametersLayout(new QFormLayout(NULL)),
  m_mainLayout(new QVBoxLayout(this)),
  m_runButton(new QPushButton("Run",this)),
  m_title(title)
{
  m_mainLayout->addLayout(m_parametersLayout);
  m_mainLayout->addStretch();
  m_mainLayout->addWidget(m_runButton);

  QObject::connect(m_runButton, SIGNAL(clicked()), this, SIGNAL(runRequest()));
}
