// Question 3

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::string;

template < class T, int maxSize > class Set
{
  T **elements;
  int size;
public:
    Set ():size (0)
  {
    elements = new T *[maxSize];
  }
  bool add (const T & element)
  {
    if (size < maxSize)
      {
	for (int i = 0; i <= size; i++)
	  {
	    int result = elements[i]->compare (element);
	    if (elements[i] != 0)
	      elements[size++] = new T (element);
	    else
	      return false;
	  }
      }
    else
      return false;
  }
  bool isElement (const T & element)
  {
    for (int i = 0; i <= size; i++)
      {
	int result = elements[i]->compare (element);
	if (result == 0)
	  return true;
	else
	  return false;
      }
  }
  int length ()
  {
    return size;
  }
  string get (int i)
  {
    return *elements[i];
  }

};

int
main ()
{
  Set < string, 100 > s;
  s.add ("This");
  s.add ("test");
  s.add ("is");
  s.add ("a");
  s.add ("test");
  s.add ("of");
  s.add ("a");
  s.add ("set");
  s.add ("object");
  s.add ("a");
  s.add ("set");
  s.add ("contains");
  s.add ("unique");
  s.add ("elements");
  for (int i = 0; i < s.length (); i++)
    cout << s.get (i) << " ";
}
