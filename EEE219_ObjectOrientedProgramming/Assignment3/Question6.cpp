// Question 6
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
  
  Song (const Song &);

};

Song :: Song (const Song &copy)
  {
    artist = copy.artist;
    title = copy.title;
    playCount = 0;
  }

int
main ()
{
  return 0;
}
