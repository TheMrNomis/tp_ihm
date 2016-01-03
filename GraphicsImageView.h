#ifndef GRAPHICSIMAGEVIEW_H
#define GRAPHICSIMAGEVIEW_H

#include <QGraphicsView>
#include <QImage>
#include <QKeyEvent>
#include <QWheelEvent>

#include "GraphicsImageScene.h"

class GraphicsImageView : public QGraphicsView
{
  Q_OBJECT

public:
  GraphicsImageView(GraphicsImageScene * scene, QWidget* parent = 0);

  virtual GraphicsImageScene* scene() const;

protected:
  virtual void keyPressEvent(QKeyEvent * e);
  virtual void keyReleaseEvent(QKeyEvent * e);
  virtual void wheelEvent(QWheelEvent * e);
  virtual void mouseMoveEvent(QMouseEvent * e);

protected:
  GraphicsImageScene * m_scene;

  bool m_ctrlPressed;
  const double m_zoomingFactor; //between 0 (no zoom) and 1 (really fast zoom)

  QPoint m_lastMousePosition;
};

#endif // GRAPHICSIMAGEVIEW_H
