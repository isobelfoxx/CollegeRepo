Question 5

#include <iostream>

using namespace std;

void
printBinary (int decimalnum)
{

  int counter;
  // The integer is 32 bits 
  for (int bits = 31; bits >= 0; bits--)
    {
      counter ++;
      int binarynum = decimalnum >> bits;
      if (binarynum & 1)
	{
	  cout << "1";
	}
      else
	{
	  cout << "0";
	}
	// adds a space after 8, 16, and 24 bits
      if (counter == 8)
	{
	  cout << " ";
	}
	 if (counter == 16)
	{
	  cout << " ";
	}
	 if (counter == 24)
	{
	  cout << " ";
	}
    }
}

int
main ()
{
  // calls function
  printBinary (216);
  // ends code
  return 0;
}
