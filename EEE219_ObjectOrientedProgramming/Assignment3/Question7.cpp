// Question 7
#include <iostream>
using namespace std;

class Song
{
private:
  string title, artist;
  int playCounter;
  static Song mostplayed;

public:
    Song (string t, string a)
  {
    title = t;
    artist = a;
    playCounter = 0;
  }

  void play ()
  {
    ++playCounter;
  }

  void print ()
  {
    cout << title << ", " << artist << ", " << playCounter << endl;
  }

  static void mostPopular (Song arr[], int size)
  {
   int most played
    for (int i = 0; i < size; i++)
      {
	arr[i].print ();
	if (playCounter[0] < playCounter[i])
	  arr[0] = arr[i] mostplayed = arr[i];
      }
    return mostplayed;
  }

  Song (const Song &);

};

Song Song::mostplayed = ("Null", "Null");

Song::Song (const Song & copy)
{
  artist = copy.artist;
  title = copy.title;
}

int
main ()
{
  Song arr[4] = { Song ("We're Good", "Dualipa"), Song ("Drivers License",
							"Olivia Rodrigo"),
    Song ("Paradise", "MEDUZA"), Song ("Bad dreams", "Faouzia")
  };
  for (int i = 0; i < 4; i++)
    arr[i].play ();
  for (int i = 0; i < 2; i++)
    arr[i].play ();
  arr[0].play ();
  for (int i = 0; i < 4; i++)
    arr[i].print ();

  return 0;

}
