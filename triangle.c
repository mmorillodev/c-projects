#include <stdlib.h>
#include <stdio.h>

// Draw a retangle triangle

int main() {
  int triangleSize = 0;

  printf("Type the size of the triangle: ");
  scanf("%i", &triangleSize);

  for(int i = 0; i < triangleSize; i++) {
    for(int j = 0; j <= i; j++) {
      printf("*");
    }
    printf("\n");
  }
  
  return 0;
}
