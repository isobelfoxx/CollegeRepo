Question 1

#include <iostream>

using namespace std;

//  print odds function
void
printOdds (int posnum)
{

  int num;			// declaring number integer

  // all numbers between 1 and the entered number
  for (num = 1; num <= posnum; num++)
    {
      if (num % 2 != 0)		// checking for odd numbers
	{
	  cout << num << ", ";	// printing all odd numbers
	}
    }
}

int
main ()				// main function
{
  printOdds (16);			// calling printodds function
  return 0;			// exiting code
}

