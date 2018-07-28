#ifndef MOUSEINTERACTORSTYLE_H
#define MOUSEINTERACTORSTYLE_H

#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkSmartPointer.h>
#include <vtkPointPicker.h>
#include <vtkPropPicker.h>
#include <vtkCamera.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkObjectFactory.h>
#include "Renderer.h"

class Renderer;

class MouseInteractorStyle : public vtkInteractorStyleTrackballCamera
{
public:
    MouseInteractorStyle();

    static MouseInteractorStyle* New() { };

    vtkTypeMacro(MouseInteractorStyle, vtkInteractorStyleTrackballCamera);

    void OnLeftButtonDown() override;

    void OnMiddleButtonDown() override;

    void OnRightButtonDown() override;

    void SetRenderer(Renderer* renderer);

private:
    Renderer* renderer_;
};

#endif // MOUSEINTERACTORSTYLE_H
