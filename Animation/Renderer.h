#ifndef RENDERER_H
#define RENDERER_H

#include <QObject>

#include "VtkRendererWidget.h"
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>

#include <vtkPolyData.h>
#include <vtkSTLReader.h>
#include <QTimer>

class Renderer : public QObject
{
    Q_OBJECT
public:
    Renderer(QWidget* parent=nullptr);

    void InitRenderer();

    VtkRendererWidget* GetVtkWidget() const;

    void SetStlFilePath(const QString &file_path);
private slots:
    void OnTimeOut();
private:
    VtkRendererWidget* vtk_widget_;
    vtkSmartPointer<vtkRenderer> vtk_renderer_;
    vtkSmartPointer<vtkActor> actor_;
    float count_;

};

#endif // RENDERER_H
