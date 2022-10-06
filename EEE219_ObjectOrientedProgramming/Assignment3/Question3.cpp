// Question 3
#include <iostream>

using namespace std;

char
frequentChar (const string & s)
{
  char answ;
  int count[256] = {0};
  int freq = 0; 
  int len = s.length ();

  // checks each letter in the string 
  for (int letter = 0; letter < len; letter++)
    {
      count[s[letter]] = count[s[letter]] + 1;
      
      if (freq < count[s[letter]]){
          freq = count[s[letter]];
          answ =  s[letter];
      }
    }
  return answ;
}

int
main ()
{
 cout << frequentChar ("lhelol");
  return 0;
}
