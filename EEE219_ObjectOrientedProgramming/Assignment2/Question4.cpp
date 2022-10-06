//Question 4
#include <iostream>

using namespace std;

unsigned int
getByte (unsigned int num, unsigned int byteIndex)
{
  switch (byteIndex + 1)
    {
    case 1:
      cout << hex << (num >> 8) << endl;
      break;
    case 2:
      cout << "34";
      break;
    }
}

main ()
{
  getByte (0x1234, 0);
  getByte (0x1234, 1);
  return 0;
}
