#ifndef FILEINFO_H
#define FILEINFO_H

#include <qwidget.h>
#include <qfileinfo.h>
#include "ui_FileInfo.h"

class FileInfo : public QWidget
{
    Q_OBJECT

public:
    FileInfo(QFileInfo info, QWidget* parent = nullptr);

private:
    Ui::FileInfo ui;
    QFileInfo m_info;

    void makeLabel();
    void makeTextBrowser();
    void scrollBarPolicyOff(QTextBrowser* obj);

};

#endif // FILEINFO_H