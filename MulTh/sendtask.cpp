#include "sendtask.h"
#include <QFile>
#include <string>
#include <QDebug>


SendTask::SendTask()
{

}
SendTask::~SendTask()
{

}

void SendTask::Destroy()
{
    wait();

}

int SendTask::GetStatus()
{
  return m_status;
}
int SendTask::GetProgress()
{
unsigned int de;
if(m_filesize<=0)    return 0;
//qDebug()<<"m_bytesread: %d m_filesize: %d"<<m_bytesread/1000000<<m_filesize/1000000;
// de =(m_bytesread*100)/m_filesize;
// qDebug()<<"GetProgress: %d "<<de;
de=(m_bytesread)/(m_filesize/100);
qDebug()<<"m_bytesread:"<<de;
return de;

}

int SendTask::BeginTask(const char*filename)
{
  strcpy(m_filepath,filename);
  m_filesize=0;
  m_bytesread=0;
  m_status=0;
  start();
  return 0;
}
void SendTask::run()
{

FILE* fp=fopen(m_filepath,"rb");
if(!fp)
{
    m_status=-1;
    return;
}
fseek(fp,0,SEEK_END);
m_filesize=ftell(fp);
fseek(fp,0,SEEK_SET);
 qDebug()<<"m_filesize: " << m_filesize;
char buf[1024];
int part = 0;
while(1)
{
    int n= fread(buf,1,1024,fp);
    if(n<=0)
    {
      qDebug()<<"read file end >>>>>>>!!!";

        break;
    }
    //m_bytesread++;
    m_bytesread+=n;
  //  qDebug() << "Read: " << m_bytesread;
  // qDebug()<<"Read: " << m_bytesread;
    part += n;
        if(part > 1024 * 32)
        {
            QThread::msleep(10); // 模拟一下
            part = 0;
        }


}
fclose(fp);
m_status=1;

}
