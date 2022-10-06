// Question 5
#include <iostream>
using namespace std;

class Song
{
private:
  string artist, title;
  int playCounter;

public:
    Song (string a, string t)
  {
    artist = a;
    title = t;
    playCounter = 0;
  }

  void play ()
  {
    ++playCounter;
  }
};


int
main ()
{
  return 0;
}
