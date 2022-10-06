// Question 10
#include <iostream>
using namespace std;

class Test
{
private:
  int i;

public:
  Test (int _i):i (_i) {}
  int get (){ return i; }
};

int
main ()
{
  Test *arr[10];
  for (int i = 0; i < 10; i++)
  arr[i] = new Test(i);
  for (int i = 0; i < 10; i++)
  cout << arr[i]->get() << endl;
}
