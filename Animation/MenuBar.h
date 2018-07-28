#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
#include <QMenu>
#include <QAction>

class MenuBar : public QMenuBar
{
public:
    MenuBar(QWidget* parent = nullptr);

    ~MenuBar();

    void AddImportAction();

public:
    QAction* import_action_;
};

#endif // MENUBAR_H
