#include "ContextMenu.h"

ContextMenu::ContextMenu(QWidget* parent)
    : QMenu(parent)
{

}

void ContextMenu::AddTransformAction()
{
    transform_action_ = addAction("Transform");
}

void ContextMenu::AddDeleteAction()
{
    delete_action_ = addAction("Delete");
}

void ContextMenu::AddAnimateAction()
{
    animate_action_ = addAction("Start Animation");
}

void ContextMenu::AddToParticleAction()
{
    to_particles_ =  addAction("To Particles");
}

void ContextMenu::AddSetColorAction()
{
    set_color_action_ = addAction("Set Color");
}

void ContextMenu::AddSetOpacityAction()
{
    set_opacity_ = addAction("Set Opacity");
}
