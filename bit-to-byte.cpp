#include <iostream>

using namespace std;

typedef unsigned char uchar;

int main() {
  uchar bits[] = {1, 1, 1, 1, 1, 1, 1, 1}; 
  int arrSize = sizeof(bits)/sizeof(uchar);

  int output = 0;

  int i = 0;
  int j = arrSize - 1;
  while (i < arrSize) {
    output |= bits[i] << j;
    i++;
    j--;
  }

  cout << output << endl;

  return 0;
}