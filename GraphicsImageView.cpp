#include "GraphicsImageView.h"
#include <QDebug>

GraphicsImageView::GraphicsImageView(GraphicsImageScene * scene, QWidget* parent):
  QGraphicsView(scene, parent),
  m_scene(scene),
  m_ctrlPressed(false),
  m_zoomingFactor(0.05),
  m_lastMousePosition()
{
}

GraphicsImageScene* GraphicsImageView::scene() const
{
  return m_scene;
}

void GraphicsImageView::keyPressEvent(QKeyEvent * e)
{
   if(e->key() == Qt::Key_Control)
     m_ctrlPressed = true;

   QGraphicsView::keyPressEvent(e);
}

void GraphicsImageView::keyReleaseEvent(QKeyEvent * e)
{
    if(e->key() == Qt::Key_Control)
      m_ctrlPressed = false;

    QGraphicsView::keyReleaseEvent(e);
}

void GraphicsImageView::wheelEvent(QWheelEvent * e)
{
    if(m_ctrlPressed)
    {
        if(   e->pixelDelta().y() > 0   //"normal" scroll wheel
           || e->pixelDelta().x() > 0)  //sideway scroll wheel
        {
          scale(1+m_zoomingFactor, 1+m_zoomingFactor);
        }
        else
        {
          scale(1-m_zoomingFactor, 1-m_zoomingFactor);
        }
    }
    else
      QGraphicsView::wheelEvent(e);
}

void GraphicsImageView::mouseMoveEvent(QMouseEvent *e)
{
  if(e->buttons() & Qt::LeftButton)
  {
    QPoint delta = e->pos() - m_lastMousePosition;
    m_lastMousePosition = e->pos();
    GraphicsImageView::wheelEvent(new QWheelEvent(e->pos(),e->globalPos(),delta,delta,delta.x()+delta.y(),Qt::Horizontal,e->buttons(),e->modifiers()));
  }
  else
  {
    m_lastMousePosition = e->pos();
    GraphicsImageView::mouseMoveEvent(e);
  }
}
