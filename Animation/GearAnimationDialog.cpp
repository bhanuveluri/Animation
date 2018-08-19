#include "GearAnimationDialog.h"

GearAnimationDialog::GearAnimationDialog(QWidget *parent)
    : QDialog(parent)
{
    this->InitializeDialog();
}

GearAnimationDialog::~GearAnimationDialog()
{

}

void GearAnimationDialog::InitializeDialog()
{
    QFormLayout* f_layout = new QFormLayout();

    QRegExp reg("[0-9.]+");
    QValidator* val = new QRegExpValidator(reg, this);

    speed_line_edit_ = new QLineEdit("0.5");
    speed_line_edit_->setValidator(val);

    QRegExp reg1("[0-9-.]+");
    QValidator* val2 = new QRegExpValidator(reg1, this);

    rot_x_line_edit_ = new QLineEdit("0.0");
    rot_x_line_edit_->setValidator(val2);

    rot_y_line_edit_ = new QLineEdit("1.0");
    rot_y_line_edit_->setValidator(val2);

    rot_z_line_edit_ = new QLineEdit("0.0");
    rot_z_line_edit_->setValidator(val2);

    f_layout->addRow("Speed :", speed_line_edit_);
    f_layout->addRow("RotX :", rot_x_line_edit_);
    f_layout->addRow("RotY :", rot_y_line_edit_);
    f_layout->addRow("RotZ :", rot_z_line_edit_);

    QHBoxLayout* h_layout = new QHBoxLayout();
    QPushButton* ok_button = new QPushButton("Ok", this);
    QPushButton* cancel_button = new QPushButton("Cancel", this);

    connect(ok_button, &QPushButton::clicked, this,  &GearAnimationDialog::accept);
    connect(cancel_button, &QPushButton::clicked, this,  &GearAnimationDialog::reject);

    h_layout->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));
    h_layout->addWidget(ok_button);
    h_layout->addWidget(cancel_button);

    QVBoxLayout* v_layout = new QVBoxLayout();
    v_layout->addLayout(f_layout);
    v_layout->addLayout(h_layout);

    this->setLayout(v_layout);
}

float GearAnimationDialog::GetSpeed() const
{
    return speed_line_edit_->text().toFloat();
}

float GearAnimationDialog::GetRotX() const
{
    return rot_x_line_edit_->text().toFloat();
}

float GearAnimationDialog::GetRotY() const
{
    return rot_y_line_edit_->text().toFloat();
}

float GearAnimationDialog::GetRotZ() const
{
    return rot_z_line_edit_->text().toFloat();
}


