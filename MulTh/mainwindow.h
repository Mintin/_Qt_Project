#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    int OnBtnSelect(); // 选择文件
    int OnSend(); // 点发送按钮

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
