#include "TransformDialog.h"

TransformDialog::TransformDialog(QWidget *parent)
    : QDialog(parent)
{
    this->InitializeDialog();
}

TransformDialog::~TransformDialog()
{

}

float TransformDialog::GetPosX()
{
    return pos_x_->text().toFloat();
}

float TransformDialog::GetPosY()
{
    return pos_y_->text().toFloat();
}

float TransformDialog::GetPosZ()
{
    return pos_z_->text().toFloat();
}

void TransformDialog::InitializeDialog()
{
    QFormLayout* layout = new QFormLayout();
    pos_x_ = new QLineEdit("0");
    pos_y_ = new QLineEdit("0");
    pos_z_ = new QLineEdit("0");

    layout->addRow("X : ", pos_x_);
    layout->addRow("Y : ", pos_y_);
    layout->addRow("Z : ", pos_z_);

    QPushButton* ok_button = new QPushButton("Ok");
    QPushButton* cancel_button = new QPushButton("Cancel");

    connect(ok_button, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancel_button, &QPushButton::clicked, this, &QDialog::reject);

    QHBoxLayout* h_layout = new QHBoxLayout();
    h_layout->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));
    h_layout->addWidget(ok_button);
    h_layout->addWidget(cancel_button);

    QVBoxLayout* v_layout = new QVBoxLayout();
    v_layout->addLayout(layout);
    v_layout->addLayout(h_layout);


    this->setLayout(v_layout);

}
