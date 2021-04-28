#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsExsample.h"
#include "DataSetting.h"
#include "FileInfo.h"

class QtWidgetsExsample : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsExsample(QWidget *parent = Q_NULLPTR);

private slots:
    void on_settingPushButton_clicked();
    void on_helpMenu_triggered();

    // シグナル/スロットの自動接続
    void on_pushButtonDirectoryOpen_clicked();
    void on_pushButtonFileOpen_clicked();
    void on_pushButtonDirectoryInfo_clicked();
    void on_pushButtonFileInfo_clicked();
    void on_pushButtonMessageBoxShow_clicked();
    void on_pushButtonTableInsert_clicked();
    void on_pushButtonExit_clicked();

private:
    Ui::QtWidgetsExsampleClass ui;
    DataSetting* setting_ui;
    FileInfo* fileinfo_ui;

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
