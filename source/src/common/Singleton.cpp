#include "Singleton.h"

Singleton* Singleton::instance = NULL;

pthread_mutex_t singletonMutex = PTHREAD_MUTEX_INITIALIZER;

Singleton* Singleton::Instance()
{
  if (!instance)
  {
    pthread_mutex_lock( &singletonMutex );
    instance = new Singleton;
    pthread_mutex_unlock(&singletonMutex);
  }
  return instance;
}

Singleton::Singleton()
{
  cout << "Singleton:Singleton()" << endl;
}

Singleton::~Singleton()
{
  cout << "Singleton:~Singleton()" << endl;
}


