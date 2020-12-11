#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <unistd.h>
#include <ctime>

using namespace std;

struct customer {
    char type;
    int* queue;
}queue_H, queue_M, queue_L;

int seat[10][10];
int             conditionMet = 0;
pthread_cond_t  cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// seller thread to serve one time slice (1 minute)
void *sell(void *threadarg) {

    int *arr = (int*)threadarg;
    pthread_mutex_lock(&mutex);

    while (!conditionMet) {
        cout << "Queue "<< arr[0] << " blocked" << endl;
        pthread_cond_wait(&cond, &mutex);
    }
//    pthread_cond_wait(&cond, &mutex);
    cout << "Customer Type : " << arr[1] << endl;
    for (int i = 0; i < 5; i++) {
        seat[0][i] = arr[i];
    }
    pthread_mutex_unlock(&mutex);
    return nullptr;
}

void *threadfunc(void *threadarg)
{
    struct customer *Customer;
    Customer = (struct customer *) threadarg;
    pthread_mutex_lock(&mutex);

    std::cout << "Thread "<< Customer->type << " blocked" << std::endl;
    pthread_cond_wait(&cond, &mutex);
    std::cout << "Thread "<< Customer->queue[0] << " awoke" << std::endl;
    for (int i = 0; i < 5; i++) {
        seat[0][i] = Customer->queue[i];
    }
    pthread_mutex_unlock(&mutex);
    return nullptr;
}

void wakeup_all_seller_threads() {
    sleep(1);
    pthread_mutex_lock(&mutex);
    conditionMet = 1;
    printf("Wake up all waiting threads...\n");
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);
}

int main() {
    int i;
    pthread_t tids[10];
    long seller_type;
    int seed = time(NULL);
    srand(seed);
    int N = 5;
    int queue[3][N];
    for (int m = 0; m < 3; m ++) {
        for (int n = 0; n < N; n++) {
            queue[m][n] = rand() % 60;
        }
        sort(queue[m], queue[m] + N);
        for (int n = 0; n < N; n++) {
            cout << queue[m][n] << " ";
        }
        cout << endl;
    }

    // Create necessary data structures for the simulator
    // Create buyers list for each seller ticket queue based on the
    // N value within an hour and have them in the seller queue

//    customer.type = 'H';
//    customer.queue = 1;
//    pthread_create(&tids[0], NULL, sell, (void*)queue[0]);

//    customer.type = 'M';
//    customer.queue = 2;
    struct customer Customer{'M', queue[1]};
    for (i = 1; i < 4; i++) {
        pthread_create(&tids[i], NULL, threadfunc, (void*)&Customer);
    }

//    customer.type = "L";
//    customer.queue = 3;
//    for (i = 4; i < 10; i++) {
//        pthread_create(&tids[i], NULL, sell, (void*)&customer);
//    }

    wakeup_all_seller_threads();

    // wait for all seller threads to exit
    for (i = 0; i < 10; i++) {
        pthread_join(tids[i], NULL);
    }

    // print out simulation results
    for (i = 0; i < 5; i++) {
        cout << seat[0][i] << " ";
    }


    return 0;
}