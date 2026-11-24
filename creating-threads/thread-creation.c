#include <_time.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *customThreadFunction() {
  for (int i = 0; i < 15; i++) {
    printf("I am a custom thread function created by Emran");
    sleep(1);
  }
  return NULL;
}

int main() {
  pthread_t thread;
  int status;

  status = pthread_create(&thread, NULL, customThreadFunction(), NULL);

  if (!status) {
    printf("Custom Thread Created Successfully \n");
  } else {
    printf("Failed to create custom thread. \n");
    return 0;
  }
}
