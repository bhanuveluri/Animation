#include "Renderer.h"
#include <QDebug>

Renderer::Renderer(QWidget *parent)
    : QObject(parent)
{
    timer_ = new QTimer();
    QObject::connect(timer_, &QTimer::timeout, this, &Renderer::OnTimeOut);
}

void Renderer::InitRenderer()
{
    vtk_widget_ = new VtkRendererWidget();

    vtk_renderer_ = vtkSmartPointer<vtkRenderer>::New();
    QColor color(0.3 * 255, 0.3 * 255, 0.3 * 255);
    vtk_renderer_->SetBackground(color.redF(), color.greenF(), color.blueF());

    vtk_widget_->GetRenderWindow()->ClearInRenderStatus();
    vtk_widget_->GetRenderWindow()->AddRenderer(vtk_renderer_);

    // Set the custom type to use for interaction.
    MouseInteractorStyle* style = new MouseInteractorStyle();
    style->SetDefaultRenderer(vtk_renderer_);
    style->SetRenderer(this);
    vtk_widget_->GetInteractor()->SetInteractorStyle(style);

     // Setup the text and add it to the renderer
    text_actor_ = vtkSmartPointer<vtkTextActor3D>::New();
    text_actor_->SetInput ( "WELCOME TO ESS INDIA" );
    text_actor_->SetPosition(0.0, 0.0, 0.0 );
    text_actor_->GetTextProperty()->SetFontSize ( 24 );
    text_actor_->GetTextProperty()->SetColor ( 1.0, 0.0, 0.0 );
    vtk_renderer_->AddActor2D ( text_actor_ );

    connect(vtk_widget_, &VtkRendererWidget::customContextMenuRequested, this, &Renderer::OnContextMenuRequested);
}

VtkRendererWidget *Renderer::GetVtkWidget() const
{
    return vtk_widget_;
}

void Renderer::AddActor(const QString &name, const QString &file_path)
{
    vtkSmartPointer<vtkSTLReader> reader = vtkSmartPointer<vtkSTLReader>::New();
    reader->SetFileName(file_path.toStdString().c_str());
    reader->Update();

    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(reader->GetOutputPort());

    actor_ = vtkSmartPointer<vtkActor>::New();
    actor_->SetMapper(mapper);

    vtk_renderer_->AddActor(actor_);

    vtk_renderer_->RemoveActor(text_actor_);

    vtk_renderer_->ResetCamera();
    vtk_widget_->update();
    map_actors_.insert({name, actor_});
}

void Renderer::DeleteActor()
{
    QString key;
    for(const auto &pair : map_actors_)
    {
        qDebug() << pair.first;
        if(pair.second == picked_actor_)
        {
            vtk_renderer_->RemoveActor(pair.second);
            key = pair.first;
            vtk_widget_->update();
        }
    }
    map_actors_.erase(key);
}

void Renderer::OnMouseLeftButtonClicked(vtkSmartPointer<vtkActor> actor)
{
    picked_actor_ = actor;
}

void Renderer::SetAnimation(bool option)
{
    if(option)
        timer_->start(10);
    else
        timer_->stop();
    count_ = 0;
}

void Renderer::OnTimeOut()
{
    count_ += 0.5;
    if(picked_actor_ != nullptr)
    {
        //actor_->SetPosition(this->TimerCount, this->TimerCount,0);
        picked_actor_->SetOrientation(0,0,0);
        picked_actor_->RotateY(count_);

        text_actor_->SetOrientation(0,0,0);
        text_actor_->RotateY(count_);
        //actor_->SetPosition(count_, 0.0, 0.0);
        vtk_widget_->update();
    }
}

void Renderer::OnContextMenuRequested(const QPoint &pos)
{
    if(picked_actor_ != nullptr)
    {
        emit ContextMenuRequestedForRenderer(pos);
    }
}

