#include "cbuiltindlg.h"
#include <QtPrintSupport/qprinter.h>
#include <QtPrintSupport/qpagesetupdialog.h>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrintPreviewDialog>
#include <QGridLayout>
#include <QDebug>
#include <QPalette>
#include <QtWidgets>
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

    gridLayout->addWidget(colorPushButton,0,0,1,1);
    gridLayout->addWidget(errorPushButton,0,1,1,1);
    gridLayout->addWidget(filePushButton,0,2,1,1);
    gridLayout->addWidget(fontPushButton,1,0,1,1);
    gridLayout->addWidget(inputPushButton,1,1,1,1);
    gridLayout->addWidget(pagePushButton,1,2,1,1);
    gridLayout->addWidget(progressPushButton,2,0,1,1);
    gridLayout->addWidget(printPushButton,2,1,1,1);
    gridLayout->addWidget(displayTextEdit,3,0,3,3);

    setLayout(gridLayout);
    setWindowTitle(QStringLiteral("內建對話盒展示"));
    resize(400,300);

    connect(colorPushButton,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(errorPushButton,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(filePushButton,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(fontPushButton,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(inputPushButton,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(pagePushButton,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(progressPushButton,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(printPushButton,SIGNAL(clicked()),this,SLOT(doPushBtn()));
}

CBuiltinDlg::~CBuiltinDlg() {}
void CBuiltinDlg::doPushBtn(){
    QPushButton* btn=qobject_cast<QPushButton*>(sender());
    if(btn==colorPushButton){
        QPalette palette=displayTextEdit->palette();
        const QColor& color=
            QColorDialog::getColor(palette.color(QPalette::Base),this,QStringLiteral("設定背景顏色"));
        if(color.isValid()){
            palette.setColor(QPalette::Base,color);
            displayTextEdit->setPalette(palette);
        }
    }
    if(btn==errorPushButton){
        QErrorMessage box(this);
        box.setWindowTitle(QStringLiteral("錯誤訊號盒"));
        box.showMessage(QStringLiteral("錯誤訊號盒實例xx:"));
        box.showMessage(QStringLiteral("錯誤訊號盒實例yy:"));
        box.showMessage(QStringLiteral("錯誤訊號盒實例zz:"));
        box.exec();
    }
    if(btn==filePushButton){
        QString fileName = QFileDialog::getOpenFileName(this, QStringLiteral("打開檔案"), ".", QStringLiteral("任何檔案(*.*)"";;文字檔(*.txt)"";;XML檔(*.xml)"));
        displayTextEdit->setText(fileName);
    }
    if(btn==fontPushButton){
        bool ok;
        const QFont& font=QFontDialog::getFont(&ok,displayTextEdit->font(),this,QStringLiteral("字體對話盒"));
        if(ok)displayTextEdit->setFont(font);
    }
    if(btn==inputPushButton){
        bool ok;
        QString text=QInputDialog::getText(this,tr("輸入對話盒"),tr("輸入文字"),QLineEdit::Normal,QDir::home().dirName(),&ok);
        if(ok && !text.isEmpty())displayTextEdit->setText(text);
    }
    if(btn==pagePushButton){
        QPrinter printer(QPrinter::HighResolution);
        QPageSetupDialog* dlg=new QPageSetupDialog(&printer,this);
        dlg->setWindowTitle(tr("頁面設定對話方塊"));
        if(dlg->exec()==QDialog::Accepted){

        }
    }
    if(btn==progressPushButton){
        QProgressDialog progress(tr("正在複製檔案..."),tr("取消"),0,10000,this);
        progress.setWindowTitle(tr("進度對話方塊"));
        progress.show();
        for(int i=0;i<10000;i++){
            progress.setValue(i);
            qApp->processEvents();
            if(progress.wasCanceled())break;
            qDebug()<<i;
            _sleep(1);
        }
        progress.setValue(10000);
    }
    if(btn==printPushButton){
        QPrinter printer(QPrinter::HighResolution);
        QPrintDialog dialog(&printer,this);
        if(dialog.exec()!=QDialog::Accepted)return;
    }
}
