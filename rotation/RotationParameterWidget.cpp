#include "RotationParameterWidget.h"

#include <QDebug>
#include <cmath>

template <typename T>
T degToRad(T a)
{
  double val = a / 180.0;
  return (val <= 1)? val : -(val-1);
}

template <typename T>
T radToDeg(T a)
{
  double val = a * 180.0;
  return (val >= 0)? val : -val + 180;
}

RotationParameterWidget::RotationParameterWidget(QWidget* parent):
  AbstractParameterWidget("Rotation", parent),
  m_angleUnit(new QWidget(this)),
  m_radButton(new QRadioButton("Rad", m_angleUnit)),
  m_degButton(new QRadioButton("Deg", m_angleUnit)),
  m_angle(new QDoubleSpinBox(this))
{
  QVBoxLayout * angleUnitLayout = new QVBoxLayout(m_angleUnit);
  angleUnitLayout->addWidget(m_degButton);
  angleUnitLayout->addWidget(m_radButton);

  m_degButton->setChecked(true);
  m_radButton->setChecked(false);

  this->setDeg(true);
  m_angle->setValue(0);

  QObject::connect(m_degButton, SIGNAL(toggled(bool)), this, SLOT(setDeg(bool)));
  QObject::connect(m_radButton, SIGNAL(toggled(bool)), this, SLOT(setRad(bool)));

  m_parametersLayout->addRow("Angle unit :", m_angleUnit);
  m_parametersLayout->addRow("Angle :", m_angle);
}

double RotationParameterWidget::getAngle() const
{
  return M_PI * ((m_degButton->isChecked())? degToRad(m_angle->value()) : m_angle->value());
}

void RotationParameterWidget::setRad(bool set)
{
  if(set)
  {
    double angleValue = degToRad(m_angle->value());
    m_angle->setSuffix("𝜋 rad");
    m_angle->setRange(-1, 1);
    m_angle->setDecimals(3);
    m_angle->setValue(angleValue);
  }
}

void RotationParameterWidget::setDeg(bool set)
{
  if(set)
  {
    double angleValue = radToDeg(m_angle->value());
    m_angle->setSuffix(" deg");
    m_angle->setRange(0, 360);
    m_angle->setDecimals(0);
    m_angle->setValue(angleValue);
  }
}
