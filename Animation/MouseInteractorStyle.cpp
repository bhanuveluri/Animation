#include "MouseInteractorStyle.h"

MouseInteractorStyle::MouseInteractorStyle()
    : renderer_(nullptr)
{

}


void MouseInteractorStyle::OnLeftButtonDown()
{
    int* pos = this->GetInteractor()->GetEventPosition();

    vtkSmartPointer<vtkPropPicker>  picker = vtkSmartPointer<vtkPropPicker>::New();
    picker->Pick(pos[0], pos[1], 0, this->GetDefaultRenderer());

    if(renderer_ != nullptr)
    {
        renderer_->OnMouseLeftButtonClicked(picker->GetActor());
    }
    // Forward events
    vtkInteractorStyleTrackballCamera::OnLeftButtonDown();
}

void MouseInteractorStyle::OnMiddleButtonDown()
{
    // Forward events
    vtkInteractorStyleTrackballCamera::OnMiddleButtonDown();
}

void MouseInteractorStyle::OnRightButtonDown()
{
    // Forward events
    vtkInteractorStyleTrackballCamera::OnRightButtonDown();
}

void MouseInteractorStyle::SetRenderer(Renderer *renderer)
{
    renderer_ = renderer;
}
