#ifndef GEARANIMATIONDIALOG_H
#define GEARANIMATIONDIALOG_H

#include <QGroupBox>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialog>
#include <QFormLayout>
#include <QRegExpValidator>

/**
 * @brief The GearAnimationDialog class
 */
class GearAnimationDialog : public QDialog
{
    Q_OBJECT
public:
    GearAnimationDialog(QWidget* parent = nullptr);

    ~GearAnimationDialog();

    float GetSpeed() const;

    float GetRotX() const;

    float GetRotY() const;

    float GetRotZ() const;

private:
    void InitializeDialog();

private:
    QLineEdit* speed_line_edit_;
    QLineEdit* rot_x_line_edit_;
    QLineEdit* rot_y_line_edit_;
    QLineEdit* rot_z_line_edit_;
};

#endif // GEARANIMATIONDIALOG_H
