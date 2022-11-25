#include <stdio.h>
#include <stdlib.h>
// Стандартный заголовок POSIX для использования библиотеки pthread
#include <pthread.h>
#define TRUE 1
#define FALSE 0
typedef unsigned int bool_t;

// Структура для хранения всех переменных, относящихся
// к разделяемому состоянию
typedef struct
{
    // Флаг, показывающий, был выведен символ 'A' или нет
    bool_t
        done;
    // Объект мьютекса для защиты критического участка
    pthread_mutex_t mtx;
    // Условная переменная для синхронизации двух потоков
    pthread_cond_t cv;
} shared_state_t;

// Инициализирует члены объекта shared_state_t
void shared_state_init(shared_state_t *shared_state)
{
    shared_state->done = FALSE;
    pthread_mutex_init(&shared_state->mtx, NULL);
    pthread_cond_init(&shared_state->cv, NULL);
}

// Уничтожает члены объекта shared_state_t
void shared_state_destroy(shared_state_t *shared_state)
{
    pthread_mutex_destroy(&shared_state->mtx);
    pthread_cond_destroy(&shared_state->cv);
}

void *thread_body_1(void *arg)
{
    shared_state_t *ss = (shared_state_t *)arg;
    pthread_mutex_lock(&ss->mtx);
    printf("A\n");
    ss->done = TRUE;
    // Шлем сигнал потокам, ожидающим условной переменной
    pthread_cond_signal(&ss->cv);
    pthread_mutex_unlock(&ss->mtx);
    return NULL;
}

void *thread_body_2(void *arg)
{
    shared_state_t *ss = (shared_state_t *)arg;
    pthread_mutex_lock(&ss->mtx);
    // Ждем, пока флаг не станет равным TRUE
    while (!ss->done)
    {
        // Ждем условную переменную
        pthread_cond_wait(&ss->cv, &ss->mtx);
    }
    printf("B\n");
    pthread_mutex_unlock(&ss->mtx);
    return NULL;
}

int main(int argc, char **argv)
{
    // Разделяемое состояние
    shared_state_t shared_state;

    // Инициализируем разделяемое состояние
    shared_state_init(&shared_state);
    // Обработчики потоков
    pthread_t thread1;
    pthread_t thread2;
    // Создаем новые потоки
    int result1 =
        pthread_create(&thread1, NULL, thread_body_1, &shared_state);
    int result2 =
        pthread_create(&thread2, NULL, thread_body_2, &shared_state);
    if (result1 || result2)
    {
        printf("The threads could not be created.\n");
        exit(1);
    }
    // Ждем, пока потоки не завершат работу
    result1 = pthread_join(thread1, NULL);
    result2 = pthread_join(thread2, NULL);
    if (result1 || result2)
    {
        printf("The threads could not be joined.\n");
        exit(2);
    }
    // Уничтожаем разделяемое состояние, освобождаем мьютекс
    // и объекты условных переменных
    shared_state_destroy(&shared_state);
    return 0;
}
