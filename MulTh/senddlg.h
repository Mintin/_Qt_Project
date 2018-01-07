#ifndef SENDDLG_H
#define SENDDLG_H
#include <sendtask.h>
#include <QDialog>

namespace Ui {
class SendDlg;
}

class SendDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SendDlg(const QString *filepath, QWidget *parent = 0);
    ~SendDlg();
  virtual void timerEvent(QTimerEvent *event);
private:
    Ui::SendDlg *ui;
   SendTask *m_task;
   int m_timerId;
};

#endif // SENDDLG_H
