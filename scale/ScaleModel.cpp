#include "ScaleModel.h"

#include <QDebug>

template <typename T>
inline T max(T const& a, T const& b)
{
  return (a > b)? a : b;
}

template <typename T>
inline T min(T const& a, T const& b)
{
  return (a < b)? a : b;
}

ScaleModel::ScaleModel()
{

}

void ScaleModel::setScaleFactor(double const& factor)
{
  m_scaleFactor = factor;
}

void ScaleModel::setInput(vpImage<vpRGBa> const& img)
{
  m_img = img;
}

void ScaleModel::run()
{
  unsigned int h_result = m_img.getHeight() * m_scaleFactor;
  unsigned int w_result = m_img.getWidth() * m_scaleFactor;

  vpImage<vpRGBa> resultImage(h_result, w_result);

  for(unsigned int i = 0; i < h_result; ++i)
    for(unsigned int j = 0; j < w_result; ++j)
    {
        double i_interpole = (double) i / m_scaleFactor;
        double j_interpole = (double) j / m_scaleFactor;

        resultImage[i][j] = interpole(i_interpole, j_interpole, m_img);
    }

  m_img = resultImage;
  emit(success());
}

vpImage<vpRGBa> ScaleModel::output() const
{
  return m_img;
}

vpRGBa ScaleModel::interpole(double i, double j, vpImage<vpRGBa> const& img) const
{
    double percentI = i - floor(i);
    double percentJ = j - floor(j);

    unsigned int iN = max((unsigned int) floor(i), 0u);
    unsigned int iS = min((unsigned int) iN + 1, img.getHeight() - 1);

    unsigned int jW = max((unsigned int) floor(j), 0u);
    unsigned int jE = min((unsigned int) jW + 1, img.getWidth() - 1);

    vpRGBa colorNW = img[iN][jW];
    vpRGBa colorNE = img[iN][jE];
    vpRGBa colorSW = img[iS][jW];
    vpRGBa colorSE = img[iS][jE];

    vpRGBa colorN = (1-percentJ) * colorNW + percentJ * colorNE;
    vpRGBa colorS = (1-percentJ) * colorSW + percentJ * colorSE;

    return (1-percentI) * colorN + percentI * colorS;
}
