#ifndef CBUILTINDLG_H
#define CBUILTINDLG_H

#include <QDialog>
#include <QPushButton>
#include <QTextEdit>
class CBuiltinDlg : public QDialog
{
    Q_OBJECT

public:
    CBuiltinDlg(QWidget *parent = nullptr);
    ~CBuiltinDlg();
private:
    QTextEdit   *displayTextEdit;
    QPushButton *colorPushButton;
    QPushButton *errorPushButton;
    QPushButton *filePushButton;
    QPushButton *fontPushButton;
    QPushButton *inputPushButton;
    QPushButton *pagePushButton;
    QPushButton *progressPushButton;
    QPushButton *printPushButton;
    QPushButton *textcolor;
private slots:
    void doPushBtn();
    void doTextcolor();
};
#endif // CBUILTINDLG_H
