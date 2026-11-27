#include <_time.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *customThreadFunction(void *arg) {
  for (int i = 0; i < 5; i++) {
    printf("I am a custom thread function created by Emran.\n");
    sleep(1);
    if (i == 3) {
      printf("My job is Done. I am now Being terminated by the programmer. \n");
      pthread_exit(NULL);
    }
  }
  return NULL;
}

int main() {
  pthread_t thread;
  pthread_create(&thread, NULL, customThreadFunction, NULL);

  for (int i = 0; i < 5; i++) {
    printf("I am the process thread created by the compiler by default. \n");
    sleep(1);
  }

  return 0;
}
