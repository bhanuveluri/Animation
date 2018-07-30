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

public:
    QAction* transform_action_;
    QAction* delete_action_;
    QAction* animate_action_;
    QAction* to_particles_;

};

#endif // CONTEXTMENU_H
