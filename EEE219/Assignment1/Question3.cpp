Question 3

#include <iostream>
#include <string>

using namespace std;

void
getAndPrintNameChars ()
{
  string name;
 
  // user enters name 
  cout << "Please enter your first name:" << endl;
  cin >> name;
  cout << endl;
  
  // gets length of string
  int length = name.length ();
  for (int number = 0; number < length; number++)
    {
      // gets characters from string
      char letter = name.at(number);
      // prints out to screen
      cout << number + 1 << ". "<< letter << endl;
    }
}

int
main ()
{
  // calls function
  getAndPrintNameChars ();
  // ends code
  return 0;
}
