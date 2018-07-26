#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    renderer_ = new Renderer();
    renderer_->InitRenderer();

    layout_ = new QVBoxLayout();
    layout_->addWidget(renderer_->GetVtkWidget());

    QWidget* w = new QWidget();
    w->setLayout(layout_);

    this->setCentralWidget(w);
}

MainWindow::~MainWindow()
{

}
