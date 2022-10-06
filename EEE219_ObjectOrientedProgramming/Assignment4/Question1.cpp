//Question 1
// SIMPLEGEOM library -EE219 design and implementation example
// Version 1 - using only class compostion
// (Version 2 will improve design by inheritance and add graphics)
// CMA - 10/20/2021 - DCU

#include <iostream>
#include <math.h>
using
  std::cout;
using
  std::endl;

#define PI acos(-1)

/***********************
 Color class
************************/

class
  Color
{
private:
  double
    _r,
    _g,
    _b;
public:
  Color ():
  _r (0.5),
  _g (0.5),
  _b (0.5)
  {
  }
  Color (double r, double g, double b):
  _r (r),
  _g (g),
  _b (b)
  {
  }
  double
  r ()
  {
    return _r;
  }
  double
  g ()
  {
    return _g;
  }
  double
  b ()
  {
    return _b;
  }
  void
  print ()
  {
    cout << "[" << _r << "," << _g << "," << _b << "]";
  }
};

/***********************
 Point class
************************/

class
  Point
{
private:
  double
    _x,
    _y;
  Color
    clr;
  void
  rotate (double angle);
public:
  Point (double x, double y):
  _x (x),
  _y (y)
  {
  }
  Point (double x, double y, const Color & color):
  _x (x),
  _y (y),
  clr (color)
  {
  }
  void
  moveBy (double x, double y)
  {
    _x += x;
    _y += y;
  }
  void
  rotate (double angle, Point pRef);
  void
  draw ()
  {
    cout << "not yet implemented" << endl;
  }
  void
  setColor (const Color & color)
  {
    clr = color;
  }
  void
  print ()
  {
    cout << "(" << _x << "," << _y << ") ";
    clr.print ();
  }
};

void
Point::rotate (double angle)
{
  double tmp_x = _x * cos (angle) - _y * sin (angle);
  double tmp_y = _x * sin (angle) + _y * cos (angle);
  _x = tmp_x;
  _y = tmp_y;
}

void
Point::rotate (double angle, Point pRef)
{
  moveBy (-pRef._x, -pRef._y);
  rotate (angle);
  moveBy (pRef._x, pRef._y);
}

/***********************
 Line class
************************/

class Line
{
private:
  Point _p1, _p2;
  Color clr;
public:
    Line (const Point & p1, const Point & p2):_p1 (p1), _p2 (p2)
  {
  }
  Line (const Point & p1, const Point & p2, const Color & color):_p1 (p1),
    _p2 (p2), clr (color)
  {
  }
  void moveBy (double x, double y)
  {
    _p1.moveBy (x, y);
    _p2.moveBy (x, y);
  }
  void rotate (double angle, Point pRef)
  {
    _p1.rotate (angle, pRef);
    _p2.rotate (angle, pRef);
  }
  void setColor (const Color & color)
  {
    clr = color;
  }
  void draw ()
  {
    cout << "not yet implemented" << endl;
  }
  void print ()
  {
    _p1.print ();
    cout << " - ";
    _p2.print ();
    cout << " Line Color: ";
    clr.print ();
  }
};

/***********************
 Triange class
************************/

class Triangle
{
private:
  Point _p1, _p2, _p3;
  Color clr;
public:
    Triangle (const Point & p1, const Point & p2, const Point & p3):_p1 (p1),
    _p2 (p2), _p3 (p3)
  {
  }
  Triangle (const Point & p1, const Point & p2, const Point & p3,
	    const Color & color):_p1 (p1), _p2 (p2), _p3 (p3), clr (color)
  {
  }
  void moveBy (double x, double y)
  {
    _p1.moveBy (x, y);
    _p2.moveBy (x, y);
    _p3.moveBy (x, y);
  }
  void rotate (double angle, Point pRef)
  {
    _p1.rotate (angle, pRef);
    _p2.rotate (angle, pRef);
    _p3.rotate (angle, pRef);
  }
  void setColor (const Color & color)
  {
    clr = color;
  }
  void draw ()
  {
    Line (_p1, _p2).draw ();
    Line (_p2, _p3).draw ();
    Line (_p3, _p1).draw ();
  }
  void print ()
  {
    _p1.print ();
    cout << " - ";
    _p2.print ();
    cout << " - ";
    _p3.print ();
    cout << " Triangle Color: ";
    clr.print ();
  }
};

/***********************
 Circle class
************************/

class Circle
{
private:
  Point centerp, _p1;
  Color clr;
public:
    Circle (const Point & cp, const Point & p1):centerp (cp),
    _p1 (p1)
  {
  }
  Circle (const Point & cp, const Point & p1, const Color & color):centerp (cp),
    _p1 (p1), clr (color)
  {
  }
  void moveBy (double x, double y)
  {
    centerp.moveBy (x, y);
    _p1.moveBy (x, y);
  }
  
  void rotate (double angle, Point pRef)
  {
    centerp.rotate (angle, pRef);
    _p1.rotate (angle, pRef);
  }
  void setColor (const Color & color)
  {
    clr = color;
  }
  void draw ()
  {
   cout << "not yet implemented" << endl;
  }
  
  void print ()
  {
    centerp.print ();
    cout << " - ";
    _p1.print ();
    cout << " Circle Colour: ";
    clr.print ();
  }
};

/***********************
 Canvas class
************************/

class Canvas
{
private:
  const int maxElements;
  int numPoints;
  int numLines;
  int numTriangles;
  Point **pArray;		// array of Point pointers
  Line **lArray;		// array of Line pointers
  Triangle **tArray;		// array of Triangle pointers
public:
    Canvas (int max_elements):maxElements (max_elements), numPoints (0),
    numLines (0), numTriangles (0)
  {
    pArray = new Point *[maxElements];
    lArray = new Line *[maxElements];
    tArray = new Triangle *[maxElements];
  }
  void add (const Point & p)
  {
    if (numPoints == maxElements)
      return;
    pArray[numPoints++] = new Point (p);
  }
  void add (const Line & l)
  {
    if (numLines == maxElements)
      return;
    lArray[numLines++] = new Line (l);
  }
  void add (const Triangle & t)
  {
    if (numTriangles == maxElements)
      return;
    tArray[numTriangles++] = new Triangle (t);
  }
  void print ()
  {
    for (int i = 0; i < numPoints; i++)
      {
	pArray[i]->print ();
	cout << endl;
      }
    for (int i = 0; i < numLines; i++)
      {
	lArray[i]->print ();
	cout << endl;
      }
    for (int i = 0; i < numTriangles; i++)
      {
	tArray[i]->print ();
	cout << endl;
      }
  }
  void draw ()
  {
    // call draw on each shape . . .
  }
  ~Canvas ()
  {
    for (int i = 0; i < numPoints; i++)
      delete pArray[i];
    delete[]pArray;
    for (int i = 0; i < numLines; i++)
      delete lArray[i];
    delete[]lArray;
    for (int i = 0; i < numTriangles; i++)
      delete tArray[i];
    delete[]tArray;
  }
};



/***********************
 Test client
************************/
int
main ()
{

  Canvas canvas (3);
  canvas.add (Point (1, 1, Color (0, 0, 0)));
  canvas.add (Line (Point (1, 1), Point (2, 2), Color (1, 0, 1)));
  canvas.add (Triangle (Point (1, 1), Point (2, 2), Point (3, 3)));
  canvas.print ();

}



/***********************
 Test methods
************************/

void
testColor ()
{
  Color clr (0.1, 0.2, 0.3);
  cout << clr.r () << clr.g () << clr.b () << endl;
}

void
testPoint ()
{
  Point p1 (1.0, 2.0);
  p1.print ();
  Point p2 (3.0, 4.0, Color (0.4, 0.5, 0.6));
  p2.setColor (Color (0.6, 0.7, 0.8));
  p2.rotate (-PI / 4, Point (1.5, 2.5));
  p2.print ();
}

void
testLine ()
{
  Line ln1 (Point (1, 2), Point (3, 4));
  ln1.print ();
  cout << endl;
  Line ln2 (Point (5, 6), Point (7, 8), Color (0.2, 0.3, 0.4));
  ln2.print ();
  cout << endl;
  ln2.moveBy (0.5, 0.8);
  ln2.print ();
}

void
testTriangle ()
{
  Triangle tri (Point (1, 2), Point (3, 4), Point (5, 6),
		Color (0.2, 0.3, 0.4));
  tri.print ();
}
void
testCircle ()
{
  Circle circ (Point (1, 2), Point (3, 4));
  circ.print ();
}
