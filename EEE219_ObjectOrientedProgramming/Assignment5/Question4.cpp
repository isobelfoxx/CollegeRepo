// Question 4
#include <iostream>
using namespace std;

void
printPatternRow (int size)
{
  if (size > 0)
    {
      printPatternRow (size - 1);
      cout << "* ";
    }
}

void
printPattern (int size)
{
  if (size > 0)
    printPattern (size - 1);
  printPatternRow (size);
  cout << endl;

}

int
main ()
{
  printPattern (10);
  return 0;
}
