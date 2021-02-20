#include <stdio.h>
#include <stdlib.h>

int isEven(int number);

int main() {
  int number = 0;
  char name[] = "Matheus";

  printf("Hello, %s. Type a number: ", name);
  scanf("%i", &number);

  printf("%i is Even? %s", number, isEven(number) ? "Yes" : "No");

  return 0;
}

int isEven(int number) {
  return number % 2 == 0;
}