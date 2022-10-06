// Question 8 
#include <iostream>

using namespace std;

class Complex
{

private:
  double real, imag;

public:
    Complex ()
  {
    real = imag = 0;
  }

  Complex (double r, double i)
  {
    real = r;
    imag = i;
  }

  void setValue ()
{
 cout << "Please enter the Real bit: ";
 cin >> real;
 cout << "Please enter the Imaginary bit: ";
 cin >> imag;
  }

  void print ();

};

int
main ()
{
    Complex ask; 
    ask.setValue();
}
