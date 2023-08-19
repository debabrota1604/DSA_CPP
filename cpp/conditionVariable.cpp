#include <pthread.h>

int value = 0;

pthread_cond_t g_cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

void thread_func1()
{
        value = 121;
        pthread_cond_signal(&g_cond);
}

void thread_func2()
{
        while(value == 0)
                pthread_cond_wait(&g_cond, &g_mutex);
}