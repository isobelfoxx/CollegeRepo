Question 9

#include <iostream>

using namespace std;

void
putLargestFirst (double arr[], int size)
{
  int largestarr;
  int position;
  double firstarr = arr[0];
  double Biggestarr = arr[0];

  // finding largest number 
  for (int normalarr = 1; normalarr < size; normalarr++)
    {
      if (arr[normalarr] > Biggestarr)
	{
	  Biggestarr = arr[normalarr];

	}
    }
  // finds largest number positin in array
  for (int normalarr = 0; normalarr < size; normalarr++)
    {
      if (arr[normalarr] == Biggestarr)
	{
	  position = normalarr;
	}
    }

  // swaps largest number with first number
  arr[0] = arr[position];
  arr[position] = firstarr;

  // prints array
  for (int normalarr = 0; normalarr < size; normalarr++)
    {
      cout << arr[normalarr];
      // prints commas for only first 4 numbers
      if (normalarr != size - 1)
	{
	  cout << ", ";
	}
    }

}

int
main ()
{
  // calls function
  double arr[] = { 99.17, 104.11, 175.90, 192.09, 92.2 };
  putLargestFirst (arr, 5);
  // ends code
  return 0;
}
