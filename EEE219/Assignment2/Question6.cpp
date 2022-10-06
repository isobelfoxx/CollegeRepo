//Question 6

#include <iostream>

using namespace std;

void
swap (int &x, int &y)
{
  int storingx = x;
  x = y;
  y = storingx;
}

void
sortAscending (int &a, int &b, int &c)
{
  if (b < a)
    {
      swap (a, b);
    }
  if (c < b)
    {
      swap (b, c);
    }
  if (b < a)
    {
      swap (a, b);
    }
}

// driver code
int
main ()
{
  int a = 3, b = 1, c = 5;
  sortAscending (a, b, c);
  cout << a << "," << b << "," << c << endl;
  return 0;
}
