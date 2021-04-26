#ifndef DATASETTING_H
#define DATASETTING_H

#include <QWidget>
#include "ui_datasetting.h"


class DataSetting : public QWidget
{
    Q_OBJECT

public:
    DataSetting(int index, QWidget* parent = nullptr);

    int getIndex() {
        return index;
    }
    void setIndex(int idx) {
        index = idx;
    }

private:
    Ui::Form ui;
    int index;
};

#endif // DATASETTING_H
