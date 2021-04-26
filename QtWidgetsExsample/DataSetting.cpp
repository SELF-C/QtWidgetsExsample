#include "datasetting.h"
#include "qlabel.h"

DataSetting::DataSetting(int index, QWidget* parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    setWindowFlags(Qt::Window);
    setWindowModality(Qt::WindowModal);

    setWindowTitle("Data Setting View");
    QString str = QString::fromLocal8Bit("データ:%1").arg(index);
    ui.label->setText(QString::fromLocal8Bit("データ:%1").arg(index));
}

