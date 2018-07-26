#include "Renderer.h"
#include <QDebug>

Renderer::Renderer(QWidget *parent)
    :QObject(parent)
{
    QTimer* timer_ = new QTimer();
    QObject::connect(timer_, &QTimer::timeout, this, &Renderer::OnTimeOut);
    timer_->start(10);
    count_ = 0;
}

void Renderer::InitRenderer()
{
    vtk_widget_ = new VtkRendererWidget();

    vtk_renderer_ = vtkSmartPointer<vtkRenderer>::New();
    QColor color(0.3 * 255, 0.3 * 255, 0.3 * 255);
    vtk_renderer_->SetBackground(color.redF(), color.greenF(), color.blueF());

    vtk_widget_->GetRenderWindow()->ClearInRenderStatus();
    vtk_widget_->GetRenderWindow()->AddRenderer(vtk_renderer_);
}

VtkRendererWidget *Renderer::GetVtkWidget() const
{
    return vtk_widget_;
}

void Renderer::SetStlFilePath(const QString &file_path)
{
    vtkSmartPointer<vtkSTLReader> reader =
            vtkSmartPointer<vtkSTLReader>::New();
    reader->SetFileName(file_path.toStdString().c_str());
    reader->Update();

    // Visualize
    vtkSmartPointer<vtkPolyDataMapper> mapper =
            vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(reader->GetOutputPort());

    actor_ = vtkSmartPointer<vtkActor>::New();
    actor_->SetMapper(mapper);

    vtk_renderer_->AddActor(actor_);
}

void Renderer::OnTimeOut()
{
    count_ += 0.5;
    //actor_->SetPosition(this->TimerCount, this->TimerCount,0);
    actor_->SetOrientation(0,0,0);
    actor_->RotateY(count_);
    //actor_->SetPosition(count_, 0.0, 0.0);
    vtk_widget_->update();
}
