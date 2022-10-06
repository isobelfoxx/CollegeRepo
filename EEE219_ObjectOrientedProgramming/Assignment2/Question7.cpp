#include <iostream>

using namespace std;

void
removeChar (const string & s, const char &c)
{
  string x = "";
  //gets the length of the string 
  int len = s.length ();
  // checks each letter in the string for the char c
  for (int letter = 0; letter < len; letter++)
    if (s[letter] != c)
      {
    // makes the outcome a new string 
	x = s[letter];
	// cout << x;
      }
}

int
main ()
{
  string s = "Isobel Fox";
  removeChar (s, 'o');
  return 0;
}
