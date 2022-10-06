Question 6

#include <iostream>

using namespace std;

void
printArray (int arr[], int size)
{
  // prints the array
  for (int count = 0; count < size; ++count)
    {
      cout << arr[count];
      // prints commas for only first 6 numbers
      if (count != 6)
	{
	  cout << ", ";
	}
    }

}

int
main ()
{
  int arr[] = { 3, 9, 15, 25, 99, 11, 76 }; // the array
  printArray (arr, 7); // calls the function
  return 0; // exits script
}
