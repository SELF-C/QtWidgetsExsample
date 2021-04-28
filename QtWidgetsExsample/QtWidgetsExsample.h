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

    // �V�O�i��/�X���b�g�̎����ڑ�
    void on_directoryOpenPushButton_clicked();
    void on_fileOpenPushButton_clicked();
    void on_directoryInfoPushButton_clicked();
    void on_fileInfoPushButton_clicked();
    void on_msgShowPushButton_clicked();
    void on_tableInsertPushButton_clicked();
    void on_exitPushPushButton_clicked();

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
