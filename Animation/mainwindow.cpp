#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    renderer_ = new Renderer(this);
    renderer_->InitRenderer();

    layout_ = new QVBoxLayout();
    layout_->addWidget(renderer_->GetVtkWidget());

    QWidget* w = new QWidget();
    w->setLayout(layout_);

    renderer_->SetStlFilePath("/home/ess-003/Desktop/GST/3DGear_new.stl");

    this->resize(500, 500);

    this->setCentralWidget(w);
}

MainWindow::~MainWindow()
{

}
