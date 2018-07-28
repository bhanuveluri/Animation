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
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <map>
#include "MouseInteractorStyle.h"
#include <vtkTextActor3D.h>


class Renderer : public QObject
{
    Q_OBJECT
public:
    Renderer(QWidget* parent=nullptr);

    void InitRenderer();

    VtkRendererWidget* GetVtkWidget() const;

    void AddActor(const QString &name, const QString &file_path);

    void DeleteActor();

    void OnMouseLeftButtonClicked(vtkSmartPointer<vtkActor> actor_);

    void SetAnimation(bool option);

signals:
    void ContextMenuRequestedForRenderer(const QPoint &pos);

private slots:
    void OnTimeOut();

    void OnContextMenuRequested(const QPoint &pos);

private:
    VtkRendererWidget* vtk_widget_;
    vtkSmartPointer<vtkRenderer> vtk_renderer_;
    vtkSmartPointer<vtkActor> actor_;
    float count_;
    std::map< QString, vtkSmartPointer<vtkActor>> map_actors_;
    vtkSmartPointer<vtkActor> picked_actor_;
    QTimer* timer_;
    vtkSmartPointer<vtkTextActor3D> text_actor_;
};

#endif // RENDERER_H
