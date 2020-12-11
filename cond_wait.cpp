#define _MULTI_THREADED
#include <pthread.h>

#include <stdio.h>
#include <unistd.h>
#include <iostream>


/* For safe condition variable usage, must use a boolean predicate and   */
/* a mutex with the condition.                                           */
int                 conditionMet = 0;
pthread_cond_t      cond  = PTHREAD_COND_INITIALIZER;
pthread_mutex_t     mutex = PTHREAD_MUTEX_INITIALIZER;

#define NTHREADS    5

void *threadfunc(void *parm)
{
    long tid = (long)parm;
    pthread_mutex_lock(&mutex);
    while (!conditionMet) {
        std::cout << "Thread "<< tid << " blocked" << std::endl;
        pthread_cond_wait(&cond, &mutex);
        std::cout << "Continue "<< tid;
    }
    std::cout << "Thread "<< tid << " awoke" << std::endl;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(int argc, char **argv)
{
    int i;
    pthread_t threadid[NTHREADS];

    printf("Enter Testcase - %s\n", "A");

    printf("Create %d threads\n", NTHREADS);
    for(i=0; i<NTHREADS; ++i) {
        pthread_create(&threadid[i], NULL, threadfunc, (void*)i);
    }

    sleep(1);  /* Sleep is not a very robust way to serialize threads */
    pthread_mutex_lock(&mutex);

    /* The condition has occurred. Set the flag and wake up any waiting threads */
    conditionMet = 1;
    printf("Wake up all waiting threads...\n");
    pthread_cond_broadcast(&cond);

    pthread_mutex_unlock(&mutex);

    for (i=0; i<NTHREADS; ++i) {
        pthread_join(threadid[i], NULL);
    }
    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex);

    printf("Main completed\n");
    return 0;
}