// Question 1
#include <iostream>

using namespace std;

void
reverseArray (double array[], int size)
{
  for (int reverse = 4; reverse >= 0; reverse--)
    {
      // Prints numbers in reverse order
      cout << array[reverse];
      // only prints "," for the first four numbers
      if (reverse != 0)
	{
	  cout << ", ";
	}
    }
}

int
main ()
{
  // declaring the array 
  double array[] = { 1.2, 2.3, 3.4, 4.9, 5.3 };
  // calling the function
  reverseArray (array, 5);
  // exits scripy
  return 0;
}
