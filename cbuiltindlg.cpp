#include "cbuiltindlg.h"
#include <QGridLayout>
CBuiltinDlg::CBuiltinDlg(QWidget *parent)
    : QDialog(parent)
{
    QGridLayout *gridLayout = new QGridLayout;
    displayTextEdit = new QTextEdit(QStringLiteral("Qt的標準通用對話盒"));
    colorPushButton = new QPushButton(QStringLiteral("顏色對話盒"));
    errorPushButton = new QPushButton(QStringLiteral("錯誤訊號盒"));
    filePushButton = new QPushButton(QStringLiteral("檔案對話盒"));
    fontPushButton = new QPushButton(QStringLiteral("字體對話盒"));
    inputPushButton = new QPushButton(QStringLiteral("輸入對話盒"));
    pagePushButton = new QPushButton(QStringLiteral("頁面設定對話盒"));
    progressPushButton = new QPushButton(QStringLiteral("進度對話盒"));
    printPushButton = new QPushButton(QStringLiteral("列印對話盒"));
    //
}

CBuiltinDlg::~CBuiltinDlg() {}
