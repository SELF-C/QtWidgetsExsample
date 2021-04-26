#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsExsample.h"
#include "DataSetting.h"

class QtWidgetsExsample : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsExsample(QWidget *parent = Q_NULLPTR);

private slots:
    void on_settingPushButton_clicked();
    void on_helpMenu_triggered();

    // シグナル/スロットの自動接続
    void on_directoryPushButton_clicked();
    void on_msgShowPushButton_clicked();
    void on_tableInsertPushButton_clicked();
    void on_exitPushPushButton_clicked();

private:
    Ui::QtWidgetsExsampleClass ui;
    DataSetting* setting_ui;

    void makeMenu();
    void makeStatusBar();
    void makeCentralWidget();
    void makeLabel();
    void makeLineEdit();
    void makeVertexTableWidget();
    void makeDataTableWidget();
    void makePushButton();
    void makeSpinBox();

};
