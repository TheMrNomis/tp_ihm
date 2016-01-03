#include "RotationModel.h"

#include <algorithm>

inline float getOldI(int i, int j, vpImage<vpRGBa> const& imgIn, vpImage<vpRGBa> const& imgOut, float const& alpha)
{
  i -= imgOut.getHeight()/2;
  j -= imgOut.getWidth()/2;

  return cos(alpha)*i + sin(alpha)*j + imgIn.getHeight()/2;
}

inline float getOldJ(int i, int j, vpImage<vpRGBa> const& imgIn, vpImage<vpRGBa> const& imgOut, float const& alpha)
{
  i -= imgOut.getHeight()/2;
  j -= imgOut.getWidth()/2;

  return -sin(alpha)*i + cos(alpha)*j + imgIn.getHeight()/2;
}

inline vpRGBa interpole(vpImage<vpRGBa> const& img, float i, float j)
{
  unsigned int N = std::max((unsigned int) floor(i), 0u);
  unsigned int S = std::min((unsigned int) ceil(i), img.getHeight() - 1);
  unsigned int W = std::max((unsigned int) floor(j), 0u);
  unsigned int E = std::min((unsigned int) ceil(j), img.getWidth() - 1);

  double percentI = i - floor(i);
  double percentJ = j - floor(j);

  vpRGBa valN = (1-percentJ) * img[N][W] + percentJ * img[N][E];
  vpRGBa valS = (1-percentJ) * img[S][W] + percentJ * img[S][E];

  return (1-percentI) * valN + percentI * valS;
}

RotationModel::RotationModel(QObject* parent):
  AbstractModel(parent),
  m_bgColor(0)
{

}

void RotationModel::setAngle(const double &angle)
{
  m_angle = angle;
}

void RotationModel::setInput(const vpImage<vpRGBa> &img)
{
  m_img = img;
}

void RotationModel::run()
{
  float cosAlpha = cos(m_angle);
  float sinAlpha = sin(m_angle);

  float h = m_img.getHeight()*cosAlpha + m_img.getWidth()*sinAlpha;
  float w = m_img.getHeight()*sinAlpha + m_img.getWidth()*cosAlpha;

  vpImage<vpRGBa> imgOut((int) ceil(h), (int) ceil(w), m_bgColor);

  for(unsigned int iOut = 0; iOut < imgOut.getHeight(); ++iOut)
    for(unsigned int jOut = 0; jOut < imgOut.getWidth(); ++jOut)
    {
      float iIn = getOldI(iOut, jOut, m_img, imgOut, m_angle);
      float jIn = getOldJ(iOut, jOut, m_img, imgOut, m_angle);

      if(iIn < 0 || iIn >= m_img.getHeight() || jIn < 0 || jIn >= m_img.getWidth())
        imgOut[iOut][jOut] = m_bgColor;
      else
        imgOut[iOut][jOut] = interpole(m_img, iIn, jIn);
    }

  m_img = imgOut;
  emit(success());
}

vpImage<vpRGBa> RotationModel::output() const
{
  return m_img;
}
