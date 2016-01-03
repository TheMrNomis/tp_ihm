#include "MainWindow.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QIcon::setThemeName("Adwaita");
  MainWindow w;
  w.show();

  return a.exec();
}
