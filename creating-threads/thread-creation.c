#include <_time.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct arguments {
  char *name;
  int age;
  char *bloodgroup;
};

// Thread function
// this creates a pointer that points to a struct, which cast to a void pointer
// as (void *) and passes to the pthread_thread function.
void *sayGreetings(void *data) {
  printf("Name: %s", ((struct arguments *)data)->name);
  printf("Age: %d\n", ((struct arguments *)data)->age);
  printf("BloodGroup: %s\n", ((struct arguments *)data)->bloodgroup);
  return NULL;
};

int main() {
  struct arguments *person =
      (struct arguments *)malloc(sizeof(struct arguments));
  printf("This is a simple data collection applictaion. \n");
  char bloodgroup[5], name[50];
  int age;
  printf("Enter the name of the person: ");
  fgets(name, 50, stdin);
  printf("Enter the age of the person: ");
  scanf("%d", age);
  printf("Enter the person's Bloodgroup: ");
  scanf("%s", bloodgroup);
}
