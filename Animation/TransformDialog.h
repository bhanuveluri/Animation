#ifndef TRANSFORMDIALOG_H
#define TRANSFORMDIALOG_H

#include <QFormLayout>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class TransformDialog : public QDialog
{
    Q_OBJECT
public:
    TransformDialog(QWidget* parent = nullptr);

    ~TransformDialog();

    float GetPosX();
    float GetPosY();
    float GetPosZ();

private:
    void InitializeDialog();

private:
    QLineEdit* pos_x_;
    QLineEdit* pos_y_;
    QLineEdit* pos_z_;
};

#endif // TRANSFORMDIALOG_H
