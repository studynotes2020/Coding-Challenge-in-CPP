#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

struct thread_data {
    int  thread_id;
    char const *message;
};

void *PrintHello(void *threadid) {
    long tid;
    tid = (long)threadid;
    cout << "Hello World! Thread ID, " << tid << endl;
    pthread_exit(NULL);
}

void *PrintHello2(void *threadarg) {
    struct thread_data *my_data;
    my_data = (struct thread_data *) threadarg;

    cout << "Thread ID : " << my_data->thread_id ;
    cout << " Message : " << my_data->message << endl;

    pthread_exit(NULL);
}

int main () {
    pthread_t threads[NUM_THREADS];
    struct thread_data td[NUM_THREADS];
    int rc;
    int i;

//    for( i = 0; i < NUM_THREADS; i++ ) {
//        cout << "main() : creating thread, " << i << endl;
//        rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);
//
//        if (rc) {
//            cout << "Error:unable to create thread," << rc << endl;
//            exit(-1);
//        }
//    }

    for( i = 0; i < NUM_THREADS; i++ ) {
        cout <<"main() : creating thread, " << i << endl;
        td[i].thread_id = i;
        td[i].message = "The is the message";
        rc = pthread_create(&threads[i], NULL, PrintHello2, (void *)&td[i]);

        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }

    pthread_exit(NULL);
}