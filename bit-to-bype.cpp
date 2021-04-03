#include <iostream>

using namespace std;

typedef unsigned char uchar;

int main()
{
  uchar bits[] = {0,1,0,0,0,1,1,1}; 

  int output = 0;
  for (int i = 0, j = sizeof(bits)/sizeof(bool); i < 8; i++, j--)
  {
    output |= bits[i] << j - 1;
  }

  cout << output << endl;

  return 0;
}