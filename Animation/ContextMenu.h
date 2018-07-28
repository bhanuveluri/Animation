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

public:
    QAction* transform_action_;
    QAction* delete_action_;
    QAction* animate_action_;

};

#endif // CONTEXTMENU_H
