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
#include <vtkProperty.h>

#include <vtkImageActor.h>
#include <vtkPNGReader.h>
#include <vtkImageActor.h>
#include <vtkImageData.h>


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

    void SetAnimation(bool option, float speed, float rot_x, float rot_y, float rot_z);

    void SetTranslation(float x, float y, float z);

    void SetColor(float r, float g, float b);

    void SetOpacity(float opacity = 0.5);

    struct Actors_Info
    {
        QString name_;
        vtkSmartPointer<vtkActor> actor_;
        float rot_x_axis_;
        float rot_y_axis_;
        float rot_z_axis_;
        bool is_animate_;
        float speed_;
        float counter_;
        Actors_Info()
            : rot_x_axis_(0.0)
            , rot_y_axis_(0.0)
            , rot_z_axis_(0.0)
            , is_animate_(false)
            , speed_(0.0f)
            , counter_(0.0)
        { }
    };

signals:
    void ContextMenuRequestedForRenderer(const QPoint &pos);

private slots:
    void OnTimeOut();

    void OnContextMenuRequested(const QPoint &pos);

private:
    void AddBackGroundRendrer(const QString &img);

private:
    VtkRendererWidget* vtk_widget_;
    vtkSmartPointer<vtkRenderer> vtk_renderer_;
    vtkSmartPointer<vtkActor> actor_;
    float speed_;
    std::map< QString, vtkSmartPointer<vtkActor>> map_actors_;
    vtkSmartPointer<vtkActor> picked_actor_;
    QTimer* timer_;
    vtkSmartPointer<vtkTextActor3D> text_actor_;
    std::map< QString, Actors_Info*> struct_map_actors_;
};

#endif // RENDERER_H
