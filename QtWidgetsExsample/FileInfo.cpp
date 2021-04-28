#include "FileInfo.h"
#include "qdatetime.h"

FileInfo::FileInfo(QFileInfo info, QWidget* parent) :
    QWidget(parent)
{
    m_info = info;

    ui.setupUi(this);
    
    makeForm();
    makeLabel();
    makeLineEdit();
    makePushButton();

}

void FileInfo::makeForm()
{
    setFixedSize(350, 430);
    setWindowTitle(QString::fromLocal8Bit("%1�̏��").arg(m_info.fileName()));
    setWindowFlags(Qt::Window);
    setWindowModality(Qt::WindowModal);
    setStyleSheet("#FileInfo {background-color: white;}");
}

void FileInfo::makeLabel()
{
    ui.labelFileName->setText(QString::fromLocal8Bit("�t�@�C����:"));
    ui.labelType->setText(QString::fromLocal8Bit("�t�@�C���̎��:"));
    ui.labelPath->setText(QString::fromLocal8Bit("�p�X:"));
    ui.labelSize->setText(QString::fromLocal8Bit("�T�C�Y:"));
    ui.labelDiskSize->setText(QString::fromLocal8Bit("�f�B�X�N�T�C�Y:"));

    ui.labelCreatedBy->setText(QString::fromLocal8Bit("�쐬����:"));
    ui.labelUpdatedBy->setText(QString::fromLocal8Bit("�X�V����:"));
    ui.labelAccessBy->setText(QString::fromLocal8Bit("�A�N�Z�X����:"));

}

void FileInfo::makeLineEdit()
{
    ui.lineEditFileName->setReadOnly(true);
    ui.lineEditFileName->setText(m_info.fileName());

    ui.lineEditType->setReadOnly(true);
    ui.lineEditType->setFrame(false);
    ui.lineEditType->setText(m_info.suffix());

    ui.lineEditPath->setReadOnly(true);
    ui.lineEditPath->setText(m_info.absolutePath());

    ui.lineEditSize->setReadOnly(true);
    ui.lineEditSize->setFrame(false);
    ui.lineEditSize->setText(QString::fromLocal8Bit("%1 �o�C�g").arg(m_info.size()));

    ui.lineEditDiskSize->setReadOnly(true);
    ui.lineEditDiskSize->setFrame(false);
    ui.lineEditDiskSize->setText("");

    ui.lineEditCreatedBy->setReadOnly(true);
    ui.lineEditCreatedBy->setFrame(false);
    ui.lineEditCreatedBy->setText(m_info.created().toString("yyyy/mm/dd hh:mm:ss"));

    ui.lineEditUpdatedBy->setReadOnly(true);
    ui.lineEditUpdatedBy->setFrame(false);
    ui.lineEditUpdatedBy->setText(m_info.lastModified().toString("yyyy/mm/dd hh:mm:ss"));

    ui.lineEditAccessBy->setReadOnly(true);
    ui.lineEditAccessBy->setFrame(false);
    ui.lineEditAccessBy->setText(m_info.lastModified().toString("yyyy/mm/dd hh:mm:ss"));

}

void FileInfo::makePushButton()
{
    ui.pushButtonClose->setText(QString::fromLocal8Bit("����"));
    connect(ui.pushButtonClose, &QPushButton::clicked, this, &QWidget::close);
}
