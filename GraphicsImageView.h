#ifndef GRAPHICSIMAGEVIEW_H
#define GRAPHICSIMAGEVIEW_H

#include <QGraphicsView>
#include <QImage>
#include <QKeyEvent>
#include <QWheelEvent>
#include <QMouseEvent>

#include "GraphicsImageScene.h"

class GraphicsImageView : public QGraphicsView
{
  Q_OBJECT

public:
  GraphicsImageView(GraphicsImageScene * scene, QWidget* parent = 0);

  void setTabIndex(int index);

  virtual GraphicsImageScene* scene() const;

public slots:
  void checkCurrentTab(int index);

protected:
  virtual void keyPressEvent(QKeyEvent * e);
  virtual void keyReleaseEvent(QKeyEvent * e);
  virtual void wheelEvent(QWheelEvent * e);

  virtual void mousePressEvent(QMouseEvent *e);
  virtual void mouseMoveEvent(QMouseEvent *e);

  QMouseEvent mapToScene(QMouseEvent * e) const;

protected:
  GraphicsImageScene * m_scene;

  bool m_ctrlPressed;
  const double m_zoomingFactor; //between 0 (no zoom) and 1 (really fast zoom)

private:
  int m_tabIndex;
};

#endif // GRAPHICSIMAGEVIEW_H
