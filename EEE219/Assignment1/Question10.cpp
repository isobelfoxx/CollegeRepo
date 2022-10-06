Question 10

#include <iostream>

using namespace std;

bool
isUnique (int *array, int size)
{

  //Running through the array once
  for (int i = 0; i < size; ++i)
    {
      // running through array to check for duplicates
      for (int j = 0; j < i; j++)
	{
          // don't compare the array value itself
	  if (i != j)
	    {
              // if there are do the following
	      if (array[i] == array[j])
		{
		  cout << "Unfortunately, there is duplicates" << endl;
		  return false;
		}
	    }
	}
    }
  cout << "There are no duplicates" << endl;
  return true;
}

int
main ()
{
  // calls function
  int arr[] = { 39, 11, 22, 22, 99, 37 };
  isUnique (arr, 6);
  // ends code
  return 0;
}
