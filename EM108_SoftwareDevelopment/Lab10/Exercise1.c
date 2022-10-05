#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declarations of dvd file data
typedef struct films
{
  char category[12];
  char filmname[12];
  char filmyear[10];
  char filmprice[10];
  char filmcode[10];
  char discount[10];
  float ffilmprice;
} films_type;
films_type films[6];

// declarations of merch file data
typedef struct merch
{
  char merchcode[20];
  char merchname[20];
  char merchprice[20];
} merch_type;
merch_type merch[11];

int mainmenu ();		//declaration of main menu function

//declaration of variables
int choice, choice1, choice2, choice3, choice4;
int contin;
int counter;
int counter1, counter2, counter3;
int point;
int result;
float saleprice;
float ffilmprice;
char fofilename[0];

int
inputfiles ()			// input files function
{
  FILE *fd;			// opening dvd file
  fd = fopen ("dvd.txt", "r");
  if (fd == NULL)
    {
      printf ("File not found.");
    }

  FILE *fm;			// opening merch file
  fm = fopen ("merch.txt", "r");
  if (fm == NULL)
    {
      printf ("File not found.");
    }


  if (point == 1)
    {
      point++;
      counter = 1;
      // reading dvd file
      while (fscanf
	     (fd, "%s %s %s %s %s %s", films[counter].category,
	      films[counter].filmname, films[counter].filmyear,
	      films[counter].filmprice, films[counter].filmcode,
	      films[counter].discount) != feof (fd))
	{
	  counter++;
	}

      counter1 = 1;
      // reading merch file
      while (fscanf (fm, "%s %s %s ", merch[counter1].merchcode,
		     merch[counter1].merchname,
		     merch[counter1].merchprice) != feof (fm))
	{
	  counter1++;
	}
      // output data
      printf ("Files Imported sucessfully\n");
    }
  else
    {
      printf ("Files already imported\n");
    }
  // input data
  printf ("Press any key to continue\n");
  scanf ("%d", &contin);
  mainmenu ();			// calling main menu
}

int
submenu1 ()			// submenu1 function
{

  // output data
  printf ("\n");
  printf ("   - Film Menu -\n");
  printf ("\n");
  for (counter2 = 1; counter2 < counter; counter2++)
    {
      printf ("%d %s\n", counter2, films[counter2].filmname);
    }

  printf ("Press 6 to return to main menu\n");
  printf ("Enter your choice  ");
  // input data
  scanf ("%d", &choice2);
  printf ("\n");
  if (choice2 == 6)
    {
      mainmenu ();
    }
  //output data
  printf ("The discount on %s is", films[choice2].filmname);
  printf (" %s percent\n", films[choice2].discount);

//output data
  printf ("The Merchandise available for %s is:\n\n",
	  films[choice2].filmname);
  for (counter3 = 1; counter3 <= counter1; counter3++)
    {


      result = strcmp (films[choice2].filmcode, merch[counter3].merchcode);




      if (result == 0)
	{
	  // calculating discounting merchandise price
	  printf ("%s; ", merch[counter3].merchname);
	  float fmerchprice;
	  float fdiscount;
	  fmerchprice = atof (merch[counter3].merchprice);
	  fdiscount = atof (films[choice2].discount);
	  saleprice = fmerchprice - (fmerchprice * (fdiscount / 100));
	  printf ("The reduced price is %.2f Euro\n", saleprice);
	}

    }

  // input data
  printf ("\nPress any key to continue\n");
  scanf ("%d", &contin);
  submenu1 ();			// calling submenu1
}

int
submenu2 ()			// submenu2
{
  //declarations
  int year;
  int ifilmyear;
  int icategory;

  // output data
  printf ("\n");
  printf ("   - Discount Menu -\n");
  printf ("\n");
  for (counter2 = 1; counter2 < counter; counter2++)
    {
      printf ("%d %s\n", counter2, films[counter2].category);

    }
  printf ("Press 6 to return to main menu\n");
  printf ("Enter your choice  ");
  // input data
  scanf ("%d:", &choice3);
  printf ("\n");
  // input data
  printf ("Please input a year of release\n");
  scanf ("%d:", &year);


  printf ("\n");
  // calculating the discounts on the filmprice
  for (counter2 = 1; counter2 < counter; counter2++)
    {
      ifilmyear = atoi (films[counter2].filmyear);
      ffilmprice = atof (films[counter2].filmprice);


      result = strcmp (films[choice3].category, films[counter2].category);
      if (ifilmyear < year)
	{
	  ffilmprice = ffilmprice - (ffilmprice * (0.3));
	}
      if (result == 0)
	{
	  ffilmprice = ffilmprice - (ffilmprice * (0.2));

	}			// output data
      films[counter2].ffilmprice = ffilmprice;
      printf ("%s: ", films[counter2].filmname);
      printf ("The reduced filmprice is %.2f Euro\n", ffilmprice);
    }
  if (choice3 == 5)
    {
      mainmenu ();
    }
  // input data
  printf ("Press any key to continue\n");
  scanf ("%d", &contin);
  mainmenu ();			// calling main menu

}

int
outputfile ()			// output data function
{
  //input data
  printf ("Please enter the desired file name: ");
  scanf ("%s", fofilename);
  FILE *fo;
  fo = fopen (fofilename, "w");	// opening file
  if (fo == NULL)
    {
      printf ("File not found.");
    }

  for (counter1 = 1; counter1 < counter; counter1++)
    {				// writing the data into the file
      fprintf (fo, "%s %s %s %s %.2f\n",
	       films[counter1].filmname, films[counter1].category,
	       films[counter1].filmyear, films[counter1].filmprice,
	       films[counter1].ffilmprice);
    }
  fclose (fo);			// closing the file

  // input data
  printf ("Press any key to continue\n");
  scanf ("%d", &contin);
  mainmenu ();			// calling main menu

}

int
category ()			//category function
{
  // output data
  printf ("\n");
  printf ("   - Category Menu -\n");
  printf ("\n");
  for (counter2 = 1; counter2 < counter; counter2++)
    {
      printf ("%d %s\n", counter2, films[counter2].category);
    }
  printf ("Press 6 to return to main menu\n");
  printf ("Enter your choice  ");
  scanf ("%d:", &choice4);

  //calculating idscounted filmprice
  for (counter1 = 1; counter1 < counter; counter1++)
    {
      result = strcmp (films[choice4].category, films[counter1].category);
      printf ("\n");

      if (result == 0)
	{
	  ffilmprice = atof (films[counter1].filmprice);
	  ffilmprice = ffilmprice - (ffilmprice * (0.2));

	  printf ("%d %s %s %s %s %.2f\n", counter1,
		  films[counter1].filmname, films[counter1].category,
		  films[counter1].filmyear, films[counter1].filmprice,
		  ffilmprice);
	}
    }
  //input data
  If (choice4 == 6)
{
mainmenu();
}
printf ("Press any key to continue\n");
  scanf ("%d", &contin);
  mainmenu ();			// calling main menu
}

int
mainmenu ()			//main menu function
{
  //output data
  printf ("   - Main Menu -\n");
  printf ("\n");
  printf ("Press 1 to input the Files\n");
  printf ("Press 2 to select a Film\n");
  printf ("Press 3 to select a Year and Category\n");
  printf ("Press 4 to export a File\n");
  printf ("Press 5 to select a category\n");
  printf ("Press 6 to exit\n");
  printf ("Enter your choice:  ");
  //input data
  scanf ("%d", &choice);
  if (choice == 1)
    {
      inputfiles ();
    }
  if (choice == 3)
    {
      submenu2 ();
    }
  if (choice == 4)
    {
      outputfile ();
    }
  if (choice == 5)
    {
      category ();
    }
  if (choice == 2)
    {
      submenu1 ();
    }
  if (choice == 6)
    {
      return 0;			// exit code
    }
}

int
main ()				// main function
{

  point = 1;
  mainmenu ();			// calling main menu
}
