#ifndef GRAPHICSIMAGESCENE_H
#define GRAPHICSIMAGESCENE_H

#include <QGraphicsScene>
#include "DrawableGraphicsScene.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMouseEvent>

class GraphicsImageScene : public DrawableGraphicsScene
{
  Q_OBJECT

public:
  GraphicsImageScene(QObject * parent = 0);

  /**
   * @brief fills the scene with an image
   * @param img: the image to fill the scene with
   */
  //void setImage(QImage const& img);

  /**
   * @brief gets the scene image
   * @return the QImage contained in the scene
   */
  //QImage image() const;

  void mousePressEvent(QMouseEvent *e);
  void mouseReleaseEvent(QMouseEvent *e);

protected:
  QImage m_img;
  QGraphicsPixmapItem * m_pixmapItem;
};

#endif // GRAPHICSIMAGESCENE_H
