#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "senddlg.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnSelect, SIGNAL(clicked()),
            this, SLOT(OnBtnSelect()));
        connect(ui->btnSend, SIGNAL(clicked()),
            this, SLOT(OnSend()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::OnBtnSelect()
{

    // 选择文件
QString filepath = QFileDialog::getOpenFileName(this, "选择文件");
if(filepath.length() > 0)
    {
        ui->textFile->setText(filepath);
    }
    return 0;
}

int MainWindow::OnSend()
{
    QString filepath=ui->textFile->text();
  SendDlg dlg(&filepath,this);
   dlg.exec();
    return 0;
}
