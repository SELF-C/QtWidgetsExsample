#include "FileInfo.h"
#include "qdatetime.h"

FileInfo::FileInfo(QFileInfo info, QWidget* parent) :
    QWidget(parent)
{
    m_info = info;

    ui.setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("%1‚Ìî•ñ").arg(m_info.fileName()));
    setWindowFlags(Qt::Window);
    setWindowModality(Qt::WindowModal);
    setStyleSheet("#FileInfo {background-color: white;}");
    
    makeTextBrowser();
}

void FileInfo::makeTextBrowser()
{

    scrollBarPolicyOff(ui.fileNameValueTextBrowser);
    ui.fileNameValueTextBrowser->setFrameStyle(QFrame::StyledPanel);
    ui.fileNameValueTextBrowser->setText(m_info.fileName());

    scrollBarPolicyOff(ui.typeValueValueTextBrowser);
    ui.typeValueValueTextBrowser->setText(m_info.suffix());

    scrollBarPolicyOff(ui.pathValueTextBrowser);
    ui.pathValueTextBrowser->setFrameStyle(QFrame::StyledPanel);
    ui.pathValueTextBrowser->setText(m_info.absolutePath());

    scrollBarPolicyOff(ui.sizeValueTextBrowser);
    ui.sizeValueTextBrowser->setText(QString::fromLocal8Bit("%1 ƒoƒCƒg").arg(m_info.size()));

    scrollBarPolicyOff(ui.diskSizeValueTextBrowser);
    ui.diskSizeValueTextBrowser->setText("");

    scrollBarPolicyOff(ui.createdByValueTextBrowser);
    ui.createdByValueTextBrowser->setText(m_info.created().toString("yyyy/mm/dd hh:mm:ss"));

    scrollBarPolicyOff(ui.updatedByValueTextBrowser);
    ui.updatedByValueTextBrowser->setText(m_info.lastModified().toString("yyyy/mm/dd hh:mm:ss"));

    scrollBarPolicyOff(ui.accessByValueTextBrowser);
    ui.accessByValueTextBrowser->setText(m_info.lastModified().toString("yyyy/mm/dd hh:mm:ss"));


}

void FileInfo::scrollBarPolicyOff(QTextBrowser* obj)
{
    obj->setFrameStyle(QFrame::NoFrame);
    obj->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    obj->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
