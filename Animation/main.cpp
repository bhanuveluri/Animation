#include "mainwindow.h"
#include <QApplication>
#include <vtkAutoInit.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    VTK_MODULE_INIT(vtkRenderingOpenGL2);
    VTK_MODULE_INIT(vtkInteractionStyle);
    VTK_MODULE_INIT(vtkRenderingFreeType);
    MainWindow w;
    w.show();

    return a.exec();
}

//return sqrt(pow(p2.x_ - p1.x_, 2) + pow(p2.y_ - p1.y_, 2) + pow(p2.z_ - p1.z_, 2));
