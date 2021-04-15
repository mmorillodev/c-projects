#include "stdio.h"
#define BYTE_SIZE 8

typedef unsigned char uchar;

short bits2Byte(const uchar bits[8]) {
  short output = 0;

  int i = 0;
  int j = BYTE_SIZE - 1;
  while (i < BYTE_SIZE) {
    output |= bits[i++] << j--;
  }

  return output;
}

int main() {
  uchar bits[] = {
    1, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1
  }; 

  short resultantArray[(sizeof(bits)/sizeof(uchar))/BYTE_SIZE];

  uchar auxArr[8];
  for(int i = 1, j = 0, k = 0; i <= sizeof(bits)/sizeof(uchar); i++) {
    auxArr[j++] = bits[i - 1];

    if(i % BYTE_SIZE == 0) {
      resultantArray[k++] = bits2Byte(auxArr);
      j = 0;
    }
  }

  printf("[");
  for(int i = 0; i < sizeof(resultantArray)/sizeof(short); i++) {
    printf("%d, ", resultantArray[i]);
  }
  printf("]");

  return 0;
}