#include <iostream>

using namespace std;

typedef unsigned char uchar;

int main() {
  uchar bits[] = {1, 1, 1, 1, 1, 1, 1, 1}; 

  int output = 0;

  int i = 0;
  int j = sizeof(bits)/sizeof(uchar) - 1;
  while (i < 8) {
    output |= bits[i] << j;
    i++;
    j--;
  }

  cout << output << endl;

  return 0;
}