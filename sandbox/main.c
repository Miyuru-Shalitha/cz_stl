#include <stdio.h>
#include <cz_threads.h>

static int counter = 0;
static Mutex mutex;

static void thread_function(void* arg) {
	int* length = arg;

	for (int i = 0; i < *length; i++) {
		mutex_lock(&mutex);
		counter++;
		mutex_unlock(&mutex);
	}
}

static void thread_function2(void* arg) {
	int* length = arg;

	for (int i = 0; i < *length; i++) {
		mutex_lock(&mutex);
		counter++;
		mutex_unlock(&mutex);
	}
}

int main(void) {
	Thread thread;
	Thread thread2;

	int length = 100000;

	mutex_init(&mutex);

	thread_init(&thread, thread_function, &length);
	thread_init(&thread2, thread_function2, &length);
	
	thread_join(&thread);
	thread_join(&thread2);

	printf("total: %d\n", counter);

	thread_close(&thread);
	thread_close(&thread2);
	mutex_close(&mutex);

	return 0;
}