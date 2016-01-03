#ifndef GRAPHICSIMAGESCENE_H
#define GRAPHICSIMAGESCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>

class GraphicsImageScene : public QGraphicsScene
{
  Q_OBJECT

public:
  GraphicsImageScene(QObject * parent = 0);

  /**
   * @brief fills the scene with an image
   * @param img: the image to fill the scene with
   */
  void setImage(QImage const& img);

  /**
   * @brief gets the scene image
   * @return the QImage contained in the scene
   */
  QImage image() const;

protected:
  QImage m_img;
  QGraphicsPixmapItem * m_pixmapItem;
};

#endif // GRAPHICSIMAGESCENE_H
