// Question 5

Q.  &a, &B means that ‘a’ and ’b’ is a reference. int &a, int &b, in the parameter list of the function means we pass them by a reference. Since we change the value of ‘a’  and  ‘’ in the function, it alters the value of the corresponding variable ‘a’ and ‘b’.

//Code
#include <iostream>

using namespace std;

void
swap (int &a, int &b)
{
  int storinga = a;
  a = b;
  b = storinga;
}


int
main ()
{
  int a = 1, b = 2;
  swap (a, b);
  cout << a << "," << b << endl;
  return 0;
}
