#ifndef CONTEXTMENU_H
#define CONTEXTMENU_H

#include <QMenu>

class ContextMenu : public QMenu
{
public:
    ContextMenu(QWidget* parent = nullptr);

    void AddTransformAction();

    void AddDeleteAction();

    void AddAnimateAction();

    void AddToParticleAction();

    void AddSetColorAction();

    void AddSetOpacityAction();
public:
    QAction* transform_action_;
    QAction* delete_action_;
    QAction* animate_action_;
    QAction* to_particles_;
    QAction* set_color_action_;
    QAction* set_opacity_;

};

#endif // CONTEXTMENU_H
