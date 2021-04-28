#ifndef DATASETTING_H
#define DATASETTING_H

#include <QWidget>
#include "ui_datasetting.h"


class DataSetting : public QWidget
{
    Q_OBJECT

public:
    DataSetting(int index, QWidget* parent = nullptr);

private:
    Ui::DataSetting ui;
    int m_index;
};

#endif // DATASETTING_H
