#include "Renderer.h"

Renderer::Renderer()
{

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
