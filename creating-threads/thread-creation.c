#include <_time.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *customThreadFunction(void *arg) {
  for (int i = 0; i < 15; i++) {
    printf("I am a custom thread function created by Emran.\n");
    sleep(1);
  }
  return NULL;
}

int main() {
  pthread_t thread;
  int status;

  status = pthread_create(&thread, NULL, customThreadFunction, NULL);

  if (!status) {
    printf("Custom Thread Created Successfully \n");
  } else {
    printf("Failed to create custom thread. \n");
    return 0;
  }

  // Main Function For loop
  for (int i = 0; i < 15; i++) {
    printf("I am the process thread created by compiler by default. \n");
    sleep(1);
  };

  return 0;
}
