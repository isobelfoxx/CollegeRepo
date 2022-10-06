Question 2

#include <iostream>

using namespace std;

void
countOdds (int arr[], int size)
{
  int counter = 0;

  cout << "Number of Odds: ";	// prints 
  for (int count = 0; count < size; ++count)
    {
      if (arr[count] % 2 != 0)
	{			// checks if number is odd
	  ++counter;		// add one to counter if number is odd
	}
    }
  cout << counter;		//prints counter value 
}

int
main ()
{
  int arr[] = { 2, 7, 13, 4, 100, 51, 9, 20, 45 };
  countOdds (arr, 9);		// calling function
  return 0;
}
