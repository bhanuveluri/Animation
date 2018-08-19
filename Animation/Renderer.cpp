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
    vtk_widget_->GetRenderWindow()->SetNumberOfLayers(2);

    //Adding background renderer
    this->AddBackGroundRendrer("/home/ess-003/Animation/Animation/Animation/Images/ess_logo.png");

    //sencond rendrer
    vtk_renderer_ = vtkSmartPointer<vtkRenderer>::New();
    vtk_renderer_->SetLayer(1);

    QColor color(0.3 * 255, 0.3 * 255, 0.3 * 255);
    vtk_renderer_->SetBackground(color.redF(), color.greenF(), color.blueF());

    vtk_widget_->GetRenderWindow()->ClearInRenderStatus();
    vtk_widget_->GetRenderWindow()->AddRenderer(vtk_renderer_);

    // Set the custom type to use for interaction.
    MouseInteractorStyle* style = new MouseInteractorStyle();
    style->SetDefaultRenderer(vtk_renderer_);
    style->SetRenderer(this);
    vtk_widget_->GetInteractor()->SetInteractorStyle(style);

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

    Actors_Info* actor_info = new Actors_Info();
    actor_info->name_ = name;
    actor_info->actor_ = actor_;
    actor_->GetProperty()->SetMaterialName(name.toStdString().c_str());
    struct_map_actors_.insert({name, actor_info});
}

void Renderer::DeleteActor()
{
    QString key;
    for(const auto &pair : map_actors_)
    {
        if(pair.second == picked_actor_)
        {
            vtk_renderer_->RemoveActor(pair.second);
            key = pair.first;
            vtk_widget_->update();
        }
    }
    map_actors_.erase(key);
    if(map_actors_.size() == 0)
    {
        picked_actor_ = nullptr;
    }
}

void Renderer::OnMouseLeftButtonClicked(vtkSmartPointer<vtkActor> actor)
{
    picked_actor_ = actor;
}

void Renderer::SetAnimation(bool option, float speed, float rot_x, float rot_y, float rot_z)
{
    if(option)
        timer_->start(50);
    //else
    //  timer_->stop();
    speed_ = 0;
    for(const auto& pair : struct_map_actors_)
    {
        Actors_Info* actor_info = pair.second;
        if(actor_info->actor_ != nullptr)
        {
            if(picked_actor_ == actor_info->actor_)
            {
                actor_info->is_animate_ = option;
                actor_info->rot_x_axis_ = rot_x;
                actor_info->rot_y_axis_ = rot_y;
                actor_info->rot_z_axis_ = rot_z;
                actor_info->speed_ = speed;
                actor_info->counter_ = 0;
            }
        }
    }
}

void Renderer::SetTranslation(float x, float y, float z)
{
    if(picked_actor_ != nullptr)
    {
        picked_actor_->SetPosition(x, y, z);
        vtk_widget_->update();
    }
}

void Renderer::SetColor(float r, float g, float b)
{
    if(picked_actor_ != nullptr)
    {
        picked_actor_->GetProperty()->SetColor(r, g, b);
        vtk_widget_->update();
    }
}

void Renderer::SetOpacity(float opacity)
{
    if(picked_actor_ != nullptr)
    {
        picked_actor_->GetProperty()->SetOpacity(opacity);
        vtk_widget_->update();
    }
}

void Renderer::OnTimeOut()
{
    for(const auto& pair : struct_map_actors_)
    {
        Actors_Info* actor_info = pair.second;
        if(actor_info->actor_ != nullptr)
        {
            if(actor_info->is_animate_)
            {
                actor_info->counter_ += actor_info->speed_;
                actor_info->actor_->SetOrientation(0,0,0);
                //actor_info->actor_->RotateY(speed_);
                actor_info->actor_->RotateWXYZ(actor_info->counter_, actor_info->rot_x_axis_, actor_info->rot_y_axis_, actor_info->rot_z_axis_);
            }
        }
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

void Renderer::AddBackGroundRendrer(const QString &img)
{
    vtkSmartPointer<vtkPNGReader> png_reader = vtkSmartPointer<vtkPNGReader>::New();
    png_reader->SetFileName ( img.toStdString().c_str() );
    png_reader->Update();

    vtkSmartPointer<vtkImageData> image_data = png_reader->GetOutput();

    vtkSmartPointer<vtkImageActor> image_actor = vtkSmartPointer<vtkImageActor>::New();
#if VTK_MAJOR_VERSION <= 5
    image_actor->SetInput(image_data);
#else
    image_actor->SetInputData(image_data);
#endif

    // Create a renderer to display the image in the background
    vtkSmartPointer<vtkRenderer> background_renderer = vtkSmartPointer<vtkRenderer>::New();
    background_renderer->SetLayer(0);
    background_renderer->InteractiveOff();
    background_renderer->AddActor(image_actor);

    vtk_widget_->GetRenderWindow()->AddRenderer(background_renderer);

    // Set up the background camera to fill the renderer with the image
    double origin[3];
    double spacing[3];
    int extent[6];
    image_data->GetOrigin( origin );
    image_data->GetSpacing( spacing );
    image_data->GetExtent( extent );

    vtkCamera* camera = background_renderer->GetActiveCamera();
    camera->ParallelProjectionOn();

    double xc = origin[0] + 0.5 * (extent[0] + extent[1])*spacing[0];
    double yc = origin[1] + 0.5 * (extent[2] + extent[3])*spacing[1];
    //double xd = (extent[1] - extent[0] + 1)*spacing[0];
    double yd = (extent[3] - extent[2] + 1)*spacing[1];
    double d = camera->GetDistance();
    camera->SetParallelScale(0.5 * yd);
    camera->SetFocalPoint(xc, yc, 0.0);
    camera->SetPosition(xc, yc, d);
}
