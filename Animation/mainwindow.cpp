#include "mainwindow.h"
#include "ImportDialog.h"
#include <QPushButton>

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
    context_menu_->AddAnimateAction();
    context_menu_->addSeparator();
    context_menu_->AddSetColorAction();
    context_menu_->AddSetOpacityAction();
    context_menu_->addSeparator();
    context_menu_->AddDeleteAction();

    connect(context_menu_->delete_action_, &QAction::triggered, [this]() {
        renderer_->DeleteActor();
    });

    connect(context_menu_->animate_action_, &QAction::triggered, this, &MainWindow::OnAnimateActionTriggered);
    connect(context_menu_->transform_action_, &QAction::triggered, this, &MainWindow::OnTransformActionTriggered);
    connect(context_menu_->set_color_action_, &QAction::triggered, this, &MainWindow::OnSetColorActionTriggrerd);
    connect(context_menu_->set_opacity_, &QAction::triggered, this, &MainWindow::OnSetOpacityActiuonTriggered);
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
    GearAnimationDialog* dlg = new GearAnimationDialog();
    //static bool option = false;
    //option = !option;
    //if(option)
    {
        if(dlg->exec() == QDialog::Accepted)
        {
            renderer_->SetAnimation(true, dlg->GetSpeed(), dlg->GetRotX(), dlg->GetRotY(), dlg->GetRotZ());
        }
    }
    dlg->deleteLater();
}

void MainWindow::OnTransformActionTriggered()
{
    TransformDialog* dlg = new TransformDialog(this);
    if(dlg->exec() == QDialog::Accepted)
    {
        renderer_->SetTranslation(dlg->GetPosX(), dlg->GetPosY(), dlg->GetPosZ());
    }
    dlg->deleteLater();
}

void MainWindow::OnSetColorActionTriggrerd()
{
    QColorDialog color_dialog;
    if(color_dialog.exec() == QColorDialog::Accepted)
    {
        QColor slected_color = color_dialog.selectedColor();
        renderer_->SetColor(slected_color.redF(), slected_color.greenF(), slected_color.blueF());
    }
}

void MainWindow::OnSetOpacityActiuonTriggered()
{
    QDialog* dlg = new QDialog();
    QFormLayout* layout = new QFormLayout();
    QRegExp reg1("[0-9.]+");
    QValidator* val = new QRegExpValidator(reg1, this);

    QLineEdit* opacity_line_edit = new QLineEdit("0.5");
    opacity_line_edit->setValidator(val);

    layout->addRow("Opcaity :", opacity_line_edit);

    QHBoxLayout* h_layout = new QHBoxLayout();
    QPushButton* ok_button = new QPushButton("Ok", this);
    QPushButton* cancel_button = new QPushButton("Cancel", this);

    connect(ok_button, &QPushButton::clicked, dlg,  &QDialog::accept);
    connect(cancel_button, &QPushButton::clicked, dlg,  &QDialog::reject);

    connect(opacity_line_edit, &QLineEdit::textChanged, [this, ok_button, opacity_line_edit]() {
        ok_button->setDisabled(false);
        if(opacity_line_edit->text().toFloat() <= 0)
            ok_button->setDisabled(true);
    });

    h_layout->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));
    h_layout->addWidget(ok_button);
    h_layout->addWidget(cancel_button);

    QVBoxLayout* v_layout = new QVBoxLayout();
    v_layout->addLayout(layout);
    v_layout->addLayout(h_layout);

    dlg->setLayout(v_layout);
    if(dlg->exec() == QDialog::Accepted)
    {
        renderer_->SetOpacity(opacity_line_edit->text().toFloat());
    }
    dlg->deleteLater();
}
