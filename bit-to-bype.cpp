#include <iostream>

using namespace std;

typedef unsigned char uchar;

int main()
{
  uchar nDesEdrv[] = {0,1,0,0,0,1,1,1}; 

  int recivedID = 0;
  for (int i = 0, j = sizeof(nDesEdrv)/sizeof(bool); i < 8; i++, j--)
  {
    recivedID |= nDesEdrv[i] << j - 1;
  }

  cout << recivedID << endl;

  return 0;
}