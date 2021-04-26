#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsExsample.h"

class QtWidgetsExsample : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsExsample(QWidget *parent = Q_NULLPTR);

private slots:
    void showSettingDialog();
    void buttonInGroupClicked(int);

    // シグナル/スロットの自動接続
    void on_directoryPushButton_clicked();
    void on_msgShowPushButton_clicked();
    void on_tableInsertPushButton_clicked();
    void on_exitPushPushButton_clicked();

private:
    Ui::QtWidgetsExsampleClass ui;

    void makeMenu();
    void makeStatusBar();
    void makeCentralWidget();
    void makeLabel();
    void makeLineEdit();
    void makeVertexTableWidget();
    void makeDataTableWidget();
    void makePushButton();
    void makeSpinBox();


    QButtonGroup* buttonGroup;
};
