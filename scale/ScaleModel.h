#ifndef SCALEMODEL_H
#define SCALEMODEL_H

#include "../AbstractModel.h"

#include <visp/vpImage.h>

class ScaleModel : public AbstractModel
{
public:
  ScaleModel();

  void setScaleFactor(double const& factor);
  void setInput(vpImage<vpRGBa> const& img);

  void run();

  vpImage<vpRGBa> output() const;

private:
  vpRGBa interpole(double i, double j, vpImage<vpRGBa> const& img) const;

private:
  double m_scaleFactor;
  vpImage<vpRGBa> m_img;

};

#endif // SCALEMODEL_H
