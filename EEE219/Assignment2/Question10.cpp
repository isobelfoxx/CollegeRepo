//Question 10
#include <iostream>
#include <cmath>

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
  int quadraticRoots (double, double, double, Complex, Complex);

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

int Complex::quadraticRoots (double a, double b, double c, Complex & r1,
			 Complex & r2)
{
  determinant = b * b - 4 * a * c;
  // real and the same value for roots
  if (determinant == 0)
    {
      r1 = (-b / 2 * a);
    }

  //real and different value for roots
  if (determinant > 0)
    {
      r1 = (-b + sqrt (determinant)) / 2 * a);
      r2 = (-b - sqrt (determinant)) / 2 * a);
    }

  // different and complete roots
  if (determinant < 0)
    {
      r1 = (-b / 2 * a) + (sqrt (determinant)) / 2 * a);
      r2 = (-b / 2 * a) - (sqrt (determinant)) / 2 * a);
    }

  return r1;
  return r1;
}

int main ()
{
  Complex r1, r2;
  int num_roots = quadraticRoots (11, 3, 10, r1, r2);
  cout << "The quadratic has " << num_roots << " root(s): ";
  r1.print ();
  if (num_roots == 2)
    {
      cout << " and ";
      r2.print ();
    }
  cout << endl;
}
