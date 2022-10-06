// Question 4
#include <iostream>
#include <cmath>
using namespace std;

class Circle
{
  int x, y, radius;
public:
    Circle (int _x, int _y, int r)
  {
    _x = x;
    _y = y;
    r = radius;
  }
  bool contains (Circle, Circle);
};

bool Circle::contains (Circle c1, Circle c2)
{
  int
    equation =
    sqrt ((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y));
  if (equation + c2.radius <= c1.radius)
      return true;
  else
      return false;
}

int
main ()
{
  Circle
  n1 (-3, 4, 5),
  n2 (-2, 2, 3);
  n1.contains (n1, n2);
  return 0;
}
