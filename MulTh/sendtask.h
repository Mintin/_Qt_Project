#ifndef SENDTASK_H
#define SENDTASK_H
#include<QThread>


class SendTask : public QThread
{
  Q_OBJECT

public:
    SendTask();
    ~SendTask();
    int BeginTask(const char *filename);
    int GetStatus();
    int GetProgress();
    void Destroy();
private:
    void run();
private:
    char m_filepath[128];
    int m_filesize;
    int m_bytesread;
    int m_status;
};

#endif // SENDTASK_H
