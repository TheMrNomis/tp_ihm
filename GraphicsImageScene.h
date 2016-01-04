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

  void mousePressEvent(QMouseEvent *e);
  void mouseReleaseEvent(QMouseEvent *e);

  void setMousePosition(QPointF const& location);
protected:
  QImage m_img;
  QGraphicsPixmapItem * m_pixmapItem;
};

#endif // GRAPHICSIMAGESCENE_H
