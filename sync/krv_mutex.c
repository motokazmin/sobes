#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

// Объект барьера
typedef struct {
    pthread_mutex_t _m;
    pthread_cond_t  _c;
    int _counter;
    int done;

} krv_barrier_t;

pthread_mutex_t _m1;
pthread_cond_t _c1;
int done = 0;

int krv_barrier_wait(krv_barrier_t *b)
{
    pthread_mutex_lock(&b->_m);

    if (b->_counter > 1) {
        b->_counter -= 1;
        while(!b->done) {
            if (b->_counter == 0)
                b->done = 0;
            pthread_cond_wait(&b->_c, &b->_m);
        }
    }
    pthread_cond_broadcast(&b->_c);
    pthread_mutex_unlock(&b->_m);
}


int krv_barrier_init(krv_barrier_t * b, unsigned int c)
{
    b->_counter = c;
    b->done = 0;
    pthread_cond_init(&b->_c, NULL);
    pthread_mutex_init(&b->_m, NULL);
}

int krv_barrier_destroy(krv_barrier_t *b)
{
    pthread_cond_destroy(&b->_c);
    pthread_mutex_destroy(&b->_m);
}

krv_barrier_t barrier;

void *thread_body_1(void *arg)
{
    printf("A\n");
    // Ждем присоединения другого потока
    krv_barrier_wait(&barrier);
    return NULL;
}

void *thread_body_2(void *arg)
{
    // Ждем присоединения другого потока
    krv_barrier_wait(&barrier);


    pthread_mutex_lock(&_m1);
    printf("B\n");
    done = 1;
    pthread_cond_signal(&_c1);
    pthread_mutex_unlock(&_m1);


    return NULL;
}

void *thread_body_3(void *arg)
{
    // Ждем присоединения другого потока
    krv_barrier_wait(&barrier);


    pthread_mutex_lock(&_m1);
    while(!done) {
        pthread_cond_wait(&_c1, &_m1);
    }
    pthread_mutex_unlock(&_m1);
    printf("C\n");


    return NULL;
}

int main(int argc, char **argv)
{
    // Инициализируем объект барьера
    krv_barrier_init(&barrier, 3);


    pthread_cond_init(&_c1, NULL);
    pthread_mutex_init(&_m1, NULL);

    // Обработчики потоков
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    // Создаем новые потоки
    int result1 = pthread_create(&thread1, NULL,
                                 thread_body_1, NULL);
    int result2 = pthread_create(&thread2, NULL,
                                 thread_body_2, NULL);
    int result3 = pthread_create(&thread3, NULL,
                                 thread_body_3, NULL);
    if (result1 || result2 || result3)
    {
        printf("The threads could not be created.\n");
        exit(1);
    }
    // Ждем, пока потоки не завершат работу
    result1 = pthread_join(thread1, NULL);
    result2 = pthread_join(thread2, NULL);
    result3 = pthread_join(thread3, NULL);
    if (result1 || result2 || result3)
    {
        printf("The threads could not be joined.\n");
        exit(2);
    }
    // Уничтожаем объект барьера
    krv_barrier_destroy(&barrier);
    pthread_cond_destroy(&_c1);
    pthread_mutex_destroy(&_m1);
    return 0;
}
