#ifndef ROTATIONMODEL_H
#define ROTATIONMODEL_H

#include "../AbstractModel.h"

#include <visp/vpImage.h>

class RotationModel : public AbstractModel
{
public:
  RotationModel(QObject * parent = 0);

  void setAngle(double const& angle);
  void setInput(vpImage<vpRGBa> const& img);

  virtual void run();

  vpImage<vpRGBa> output() const;

private:
  double m_angle;
  vpImage<vpRGBa> m_img;

  const vpRGBa m_bgColor;
};

#endif // ROTATIONMODEL_H
