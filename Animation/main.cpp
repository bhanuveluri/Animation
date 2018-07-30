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
