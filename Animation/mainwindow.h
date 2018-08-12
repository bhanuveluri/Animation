#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "VtkRendererWidget.h"
#include <QVBoxLayout>
#include "Renderer.h"
#include "MenuBar.h"
#include "ContextMenu.h"
#include "objects_volume_generator.hpp"
#include "mesh_object.hpp"
#include "TransformDialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private:
    void InitializeWindow();

    void SetMenuBar();

    void SetRenderer();

    void AddContextMenu();

    void CreateConnections();

private slots:
    void OnImportActionTriggered();

    void OnContextMenuRequested(const QPoint &pos);

    void OnAnimateActionTriggered();

    void OnToParticleActionTriggered();

    void OnTransformActionTriggered();

private:
    QVBoxLayout* layout_;
    Renderer* renderer_;
    MenuBar* menu_bar_;
    ContextMenu* context_menu_;
};

#endif // MAINWINDOW_H
