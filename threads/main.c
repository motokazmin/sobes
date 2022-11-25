#include <stdio.h>
#include <stdlib.h>
// Стандартный заголовок POSIX для использования библиотеки pthread
#include <pthread.h>

// Эта функция содержит логику, которая должна выполняться
// как тело отдельного потока
void* thread_body(void* arg) {
	printf("Hello from first thread!\n");
	return NULL;
}

int main(int argc, char** argv) {
	// Обработчик потоков
	pthread_t thread;

	// Создаем новый поток
	int result = pthread_create(&thread, NULL, thread_body, NULL);
	// Если создание потока завершилось неудачно
	if (result) {
		printf("Thread could not be created. Error number: %d\n", result);
		exit(1);
	}


	// Ждем, пока созданный поток не завершит работу
	result = pthread_join(thread, NULL);
	// Если присоединение потока оказалось неудачным
	if (result) {
		printf("The thread could not be joined. Error number: %d\n", result);
		exit(2);
	}

	return 0;
}
