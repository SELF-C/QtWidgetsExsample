#include "datasetting.h"
#include "qlabel.h"

DataSetting::DataSetting(int index, QWidget* parent) :
    QWidget(parent)
{
    m_index = index;

    ui.setupUi(this);
    setWindowFlags(Qt::Window);
    setWindowModality(Qt::WindowModal);

    setWindowTitle(QString::fromLocal8Bit("Data %1 Setting").arg(m_index));
    QString str = QString::fromLocal8Bit("データ%1").arg(m_index);
    ui.label->setText(QString::fromLocal8Bit("データ:%1").arg(m_index));
}

