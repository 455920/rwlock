//////////////////////////////
//读写锁
//三个关系
//读者和读者没有关系
//写着和写着互斥
//读者和读者同步与互斥关系
/////////////////////////////





#include<iostream>
#include<pthread.h>
#include<unistd.h>


int  value=0;
pthread_rwlock_t g_rwlock;


using namespace std;

int g_count=0;


void* Read(void* arg)
{
  (void)arg;
  while(1)
  {
    pthread_rwlock_rdlock(&g_rwlock);
    cout<<"count="<<g_count<<endl;
    pthread_rwlock_unlock(&g_rwlock);
   usleep(12345);
  }
  return NULL;
}

void* Write(void* arg)
{
  (void)arg;
  while(1)
  {
    pthread_rwlock_wrlock(&g_rwlock);
  ++g_count;
    pthread_rwlock_unlock(&g_rwlock);
  usleep(123456);
  }
  return NULL;
}


int main()
{
    pthread_t tid1,tid2;
    
    pthread_rwlock_init(&g_rwlock,NULL);

    pthread_create(&tid1,NULL,Read,NULL);
    pthread_create(&tid2,NULL,Write,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);



  return 0;
}
