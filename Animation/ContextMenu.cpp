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
    animate_action_ = addAction("Animate");
}
