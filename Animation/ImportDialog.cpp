#include "ImportDialog.h"
#include <QRegExpValidator>

ImportDialog::ImportDialog(QWidget *parent)
    : QDialog(parent)
{
    this->InitializeDialog();
}

ImportDialog::~ImportDialog()
{

}

QString ImportDialog::GetName() const noexcept
{
    return name_;
}

QString ImportDialog::GetFilePath() const noexcept
{
    return file_path_;
}

void ImportDialog::InitializeDialog()
{
    QVBoxLayout* v_layout = new QVBoxLayout();

    QHBoxLayout* h_layout1 = new QHBoxLayout();

    QLabel* label = new QLabel("Name :", this);
    name_line_edit_ = new QLineEdit("Untitle", this);
    QRegExp reg("[a-zA-Z0-9]+");
    QRegExpValidator *validator = new QRegExpValidator(reg, this);
    name_line_edit_->setValidator(validator);
    h_layout1->addWidget(label);
    h_layout1->addWidget(name_line_edit_);

    QHBoxLayout* h_layout2 = new QHBoxLayout();

    QLabel* label1 = new QLabel("File path :", this);
    file_path_line_edit_ = new QLineEdit(this);

    browse_button_ = new QPushButton("Browse", this);
    connect(browse_button_, &QPushButton::clicked, this,  &ImportDialog::OnBrowseButtonCliked);

    h_layout2->addWidget(label1);
    h_layout2->addWidget(file_path_line_edit_);
    h_layout2->addWidget(browse_button_);

    QHBoxLayout* h_layout3 = new QHBoxLayout();
    QPushButton* ok_button = new QPushButton("Ok", this);
    QPushButton* cancel_button = new QPushButton("Cancel", this);

    connect(ok_button, &QPushButton::clicked, this,  &ImportDialog::OnOkButtonCliked);
    connect(cancel_button, &QPushButton::clicked, this,  &ImportDialog::reject);

    h_layout3->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));
    h_layout3->addWidget(ok_button);
    h_layout3->addWidget(cancel_button);

    v_layout->addLayout(h_layout1);
    v_layout->addLayout(h_layout2);
    v_layout->addLayout(h_layout3);

    this->setLayout(v_layout);
}

void ImportDialog::OnBrowseButtonCliked()
{
    file_path_ = QFileDialog::getOpenFileName(this, tr("Select File"), "", "*.stl");
    file_path_line_edit_->setText(file_path_);
    QFileInfo file_info(file_path_);
    name_line_edit_->setText(file_info.fileName().replace(".stl", ""));
}

void ImportDialog::OnOkButtonCliked()
{
    name_ = name_line_edit_->text();
    file_path_ = file_path_line_edit_->text();
    this->accept();
}
