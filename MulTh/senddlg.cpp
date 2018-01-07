#include "senddlg.h"
#include "ui_senddlg.h"
#include <QDebug>
#include <QMessageBox>
#include <GBK.h>
#include <QTextCodec>


SendDlg::SendDlg(const QString*filepath, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SendDlg)
{
    ui->setupUi(this);
    m_task=new SendTask();
    QByteArray ba = filepath->toLatin1(); // must
    m_task->BeginTask(ba.data());
    m_timerId=startTimer(100);

}

SendDlg::~SendDlg()
{
    delete ui;
}

void SendDlg::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==m_timerId){
   // int status =m_task->GetStatus();
    int progress=m_task->GetProgress();
    ui->progressBar->setValue(progress);

    if(m_task->GetStatus()==1)
    {
        qDebug()<<"task 123 end";
        m_task->Destroy();
        delete m_task;
        killTimer(m_timerId);
        this->accept();
        // QString::fromLocal8Bit
        QTextCodec *codec = QTextCodec::codecForName("GBK");
        QTextCodec::setCodecForLocale(codec);


         //  QTextCodec::setCodecForTr(codec);
       QMessageBox::information(this, GBK::ToUnicode("message"),QString::fromLocal8Bit("updata OK"));
    }

    qDebug()<<"task end !!!!!"<<m_task->GetStatus();// qDebug()<<"timr QTimerEvent!!!!!";
}
}
