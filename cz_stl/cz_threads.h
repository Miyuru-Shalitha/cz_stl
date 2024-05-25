#ifndef CZ_THREAD_H
#define CZ_THREAD_H

#ifdef _WIN32
#include <Windows.h>

typedef void (*ThreadFunction)(void*);

typedef struct {
	DWORD id;
	HANDLE handle;
	ThreadFunction function;
	void* argument;
} Thread;

typedef struct {
	HANDLE handle;
} Mutex;

static DWORD WINAPI win_thread_function(LPVOID arg) {
	Thread* thread = (Thread*)arg;
	thread->function(thread->argument);
	return 0;
}

void thread_init(Thread* thread, ThreadFunction thread_function, void* argument) {
	thread->function = thread_function;
	thread->argument = argument;
	thread->handle = CreateThread(NULL, 0, win_thread_function, thread, 0, &thread->id);
}

void thread_join(Thread* thread) {
	WaitForSingleObject(thread->handle, INFINITE);
}

void thread_close(Thread* thread) {
	CloseHandle(thread->handle);
}

void mutex_init(Mutex* mutex) {
	mutex->handle = CreateMutex(NULL, FALSE, NULL);
}

void mutex_lock(Mutex* mutex) {
	WaitForSingleObject(mutex->handle, INFINITE);
}

void mutex_unlock(Mutex* mutex) {
	ReleaseMutex(mutex->handle);
}

void mutex_close(Mutex* mutex) {
	CloseHandle(mutex->handle);
}

#endif

#endif