// Question 5
#include <iostream>
using namespace std;

double pow(double base, unsigned int raisedpower)
{
    if (raisedpower != 0)
        return (base*pow(base, raisedpower-1));
    else
        return 1;
}

int
main ()
{
  cout<<pow(10,0);
  return 0;        
}
