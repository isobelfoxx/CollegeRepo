// Question 9 
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
 cout << "Please enter the Real bit:";
 cin >> real;
 cout << "Please enter the Imaginary bit:";
 cin >> imag;
  }

  void print ();

};

void
Complex::print ()
{
  if (imag < 0)
    cout << real << imag << "j" << endl;
  else if (imag > 0)
    cout << real << " + " << imag << "j" << endl;
  if (imag == 0)
    cout << real << endl;
  else if (real == 0)
    cout << imag << "j" << endl;
}

int
main ()
{
  Complex c1 (3, 4), c2 (1, 3), c3 (12, 20);
  c1.print ();
  cout << endl;
  c2.print ();
  cout << endl;
  c3.print ();
  cout << endl;
}
