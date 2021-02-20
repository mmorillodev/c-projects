#include <stdlib.h>
#include <stdio.h>

// Draw an equilateral triangle
// impl1 is more complex and more costly 
// but was the first implementation that came to my mind

void impl1(int size) {
  for(int i = 1; i <= size; i++) {
    for(int j = size - i; j > 0; j--) {
      printf(" ");
    }

    for(int j = 0; j < size - (size - i); j++) {
      printf("* ");
    }

    printf("\n");
  }
}

void impl2(int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      printf(j + i >= size - 1 ? "* " : " ");
    }

    printf("\n");
  }
}

int main() {
  int size = 0;

  printf("Type the size of the triangle: ");
  scanf("%i", &size);

  printf("\nResult:\n\n");
  impl2(size);

  return 0;
}