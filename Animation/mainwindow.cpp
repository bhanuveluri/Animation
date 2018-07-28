#include "mainwindow.h"
#include "ImportDialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , menu_bar_(nullptr)
    , renderer_(nullptr)
{
    this->InitializeWindow();
}

MainWindow::~MainWindow()
{

}

void MainWindow::InitializeWindow()
{
    this->SetRenderer();
    this->SetMenuBar();
    this->AddContextMenu();

    QWidget* w = new QWidget();
    w->setLayout(layout_);
    this->resize(500, 500);
    this->setCentralWidget(w);

    this->CreateConnections();
}

void MainWindow::SetMenuBar()
{
    menu_bar_ = new MenuBar(this);
    menu_bar_->AddImportAction();
    this->setMenuBar(menu_bar_);
}

void MainWindow::SetRenderer()
{
    renderer_ = new Renderer(this);
    renderer_->InitRenderer();

    layout_ = new QVBoxLayout();
    layout_->addWidget(renderer_->GetVtkWidget());

    connect(renderer_, &Renderer::ContextMenuRequestedForRenderer, this, &MainWindow::OnContextMenuRequested);
}

void MainWindow::AddContextMenu()
{
    context_menu_ = new ContextMenu(this);
    context_menu_->AddTransformAction();
    context_menu_->AddDeleteAction();
    context_menu_->AddAnimateAction();

    connect(context_menu_->delete_action_, &QAction::triggered, [this]() {
        renderer_->DeleteActor();
    });

    connect(context_menu_->animate_action_, &QAction::triggered, this, &MainWindow::OnAnimateActionTriggered);
}

void MainWindow::CreateConnections()
{
    connect(menu_bar_->import_action_, &QAction::triggered, this, &MainWindow::OnImportActionTriggered);
}

void MainWindow::OnImportActionTriggered()
{
    ImportDialog* import_dlg = new ImportDialog(this);
    if(import_dlg->exec() == QDialog::Accepted)
    {
        QString name = import_dlg->GetName();
        QString path = import_dlg->GetFilePath();
        renderer_->AddActor(name, path);
    }
}

void MainWindow::OnContextMenuRequested(const QPoint &pos)
{
    context_menu_->exec(pos);
}

void MainWindow::OnAnimateActionTriggered()
{
    static bool option = false;
    option = !option;
    renderer_->SetAnimation(option);
}
