Question 8

#include <iostream>

using namespace std;

//pattern function
void
printNumberPattern (int n)
{
  // declaring variables
  int firstline;
  int triangle;
  // for loop within a for loop creates the triangle shape
  for (firstline = n; firstline > 0; --firstline)
    {
      for (triangle = firstline; triangle > 0; --triangle)
	{
	  // prints the numbers
	  cout << triangle;
	}
      // new line
      cout << "\n";
    }
}

//main menu
int
main ()
{
  // calls print number pattern function
  printNumberPattern (10);
  // exits script
  return 0;
}
