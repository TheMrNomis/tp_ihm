#ifndef ROTATIONPARAMETERWIDGET_H
#define ROTATIONPARAMETERWIDGET_H

#include "../AbstractParameterWidget.h"

#include <QDoubleSpinBox>
#include <QButtonGroup>
#include <QRadioButton>

class RotationParameterWidget : public AbstractParameterWidget
{
  Q_OBJECT

public:
  RotationParameterWidget(QWidget * parent = 0);

  double getAngle() const;

private slots:
  void setRad(bool set);
  void setDeg(bool set);

private:
  QWidget * m_angleUnit;
  QRadioButton * m_radButton;
  QRadioButton * m_degButton;
  QDoubleSpinBox * m_angle;
};

#endif // ROTATIONPARAMETERWIDGET_H
