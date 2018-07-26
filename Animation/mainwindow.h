#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "VtkRendererWidget.h"
#include <QVBoxLayout>
#include "Renderer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QVBoxLayout* layout_;
    Renderer* renderer_;
};

#endif // MAINWINDOW_H
