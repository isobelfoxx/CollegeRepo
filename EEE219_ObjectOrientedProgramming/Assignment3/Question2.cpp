// Question 2

#include <iostream>
using namespace std;

string
prefixMatch (const string & a, const string & b)
{
  //gets the length of the string 
  string s = "";
  int len;

  // setting len = the longest word
  if (a.length ()> b.length ())
    len = a.length ();
  else
    len = b.length ();
    
  for (int letter = 0; letter < len; letter++){
    if (a[letter] == b[letter])
    s = s + b[letter];
  }
   return s; 
}

int
main ()
{
  cout << prefixMatch ("hellop", "help");
  return 0;
}
