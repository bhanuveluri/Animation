#include "MenuBar.h"

MenuBar::MenuBar(QWidget *parent)
    : QMenuBar(parent)
{

}

MenuBar::~MenuBar()
{

}

void MenuBar::AddImportAction()
{
    QMenu* file_menu = new QMenu("File");
    import_action_ = new QAction("Import", this);
    file_menu->addAction(import_action_);
    this->addMenu(file_menu);
}
