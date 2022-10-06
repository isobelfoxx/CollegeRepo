// Question 2
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
}

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

void
sort (double arr[], int size)
{

  double temparr[size];

  for (int i = 0; i < size; i++)
    {
      putLargestFirst (arr, size);

      temparr[i] = arr[0];
      arr[0] = 0;
    }

  for (int i = 0; i < 5; i++)
    {
      arr[i] = temparr[i];
    }

  reverseArray (arr, size);

}

int
main ()
{
  // calls function
  double arr[] = { 99.17, 4.11, 175.90, 192.09, 92.2 };
  sort (arr, 5);
  // ends code
  return 0;
}
