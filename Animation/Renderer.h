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
class Renderer : public QObject
{
public:
    Renderer();

    void InitRenderer();

    VtkRendererWidget* GetVtkWidget() const;

private:
    VtkRendererWidget* vtk_widget_;
    vtkSmartPointer<vtkRenderer> vtk_renderer_;

};

#endif // RENDERER_H
