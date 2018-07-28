#ifndef IMPORTDIALOG_H
#define IMPORTDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFileDialog>

class ImportDialog : public QDialog
{
    Q_OBJECT
public:
    ImportDialog(QWidget* parent = nullptr);

    ~ImportDialog();

    QString GetName() const noexcept;

    QString GetFilePath() const noexcept;

private:
    void InitializeDialog();

private slots:
    void OnBrowseButtonCliked();

    void OnOkButtonCliked();

private:
    QPushButton* browse_button_;
    QLineEdit* name_line_edit_;
    QLineEdit* file_path_line_edit_;
    QString name_;
    QString file_path_;
};

#endif // IMPORTDIALOG_H
