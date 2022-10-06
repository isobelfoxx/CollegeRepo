//Question 2

#include <iostream>
using namespace std;

class Complex
{
private:
  double re;
  double im;
public:
    Complex ():re (0), im (0)
  {
  };
  Complex (double r, double i):re (r), im (i)
  {
  };
  Complex operator+ (const Complex & c)
  {
    return Complex (re + c.re, im + c.im);
  }
  Complex operator- (const Complex & c)
  {
    return Complex (re - c.re, im - c.im);
  }
  Complex operator* (const Complex & c)
  {
    return Complex ((re * c.re - im * c.im), (re * c.im + im * c.re));
  }
  Complex operator/ (const Complex & c)
  {
    return Complex ((re * c.re + im * c.im) / (c.re * c.re + c.im * c.im),
		    (im * c.re - re * c.im) / (c.re * c.re + c.im * c.im));
  }
  friend ostream & operator<< (ostream & os, const Complex & c)
  {
    if (c.im < 0)
      os << c.re << c.im << "j";
    else
      os << c.re << " + " << c.im << "j";
    return os;
  }
};

int
main ()
{
  Complex c1 (1, -2);
  Complex c2 (3, -4);
  Complex c3 (-3, 2);
  cout << (c1 + c2 - c2 - c1);
  cout << endl;
  cout << ((c1 - c2) / c3 + c1 * c3);
  return 0;
}
