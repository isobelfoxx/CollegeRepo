#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declarations of data in file
typedef struct cars
{
  int year;
  char number[10];
  char colour[9];
  float engine;
  int calculatedtax;
} cars_type;
cars_type cars[7];

//declarations
int choice;
int counter, counter1;
int continu;

//declaration of main  menu function
int mainmenu ();		

int
inputfiles ()			//input  file function
{
  FILE *fi;			// opening the file
  fi = fopen ("indata.txt", "r");
  if (fi == NULL)
    {
      printf ("File not found.");
    }

  counter = 1;
  //reading the file
  while (fscanf
	 (fi, "%d %s %s %f ", &cars[counter].year,
	  cars[counter].number, cars[counter].colour,
	  &cars[counter].engine) != feof (fi))
    {
      // printing the file
      /*  printf ("\n %d %d %s %s %f", counter, cars[counter].year,
         cars[counter].number, cars[counter].colour,
         cars[counter].engine);
       */
      counter++;

    }
  // output data
  printf ("files successfully imported\n");
  printf ("\n");
  printf ("Press any key to continue\n");
  // Input  data
  scanf ("%d", &continu);
  mainmenu ();
}

int
tax ()				// tax function
{
  for (counter1 = 1; counter1 < counter; counter1++)
    {
      // tax calculation 
      if (cars[counter1].year > 2015)
	{
	  if (cars[counter1].engine <= 1.6)
	    {
	      printf ("car%d:%s, The tax is 150 Euros\n", counter1,
		      cars[counter1].number);
	      cars[counter1].calculatedtax = 150;
	    }
	  else
	    {
	      printf ("car%d:%s, The tax is 300 Euros\n", counter1,
		      cars[counter1].number);
	      cars[counter1].calculatedtax = 300;
	    }
	}
      else
	{
	  if (cars[counter1].engine < 1.4)
	    {
	      printf ("car%d:%s, The tax is 200 Euros\n", counter1,
		      cars[counter1].number);
	      cars[counter1].calculatedtax = 200;
	    }
	  else if (cars[counter1].engine >= 1.6)
	    {
	      printf ("car%d:%s, The tax is 600 Euros\n", counter1,
		      cars[counter1].number);
	      cars[counter1].calculatedtax = 600;
	    }
	  else if (1.4 < cars[counter1].engine < 1.6)
	    {
	      printf ("car%d:%s, The tax is 400 Euros\n", counter1,
		      cars[counter1].number);
	      cars[counter1].calculatedtax = 400;
	    }
	}
    }
  printf ("\n");
  printf ("Press any key to continue\n");
  scanf ("%d", &continu);
  mainmenu ();
}

int
outputfiles ()			// output files function
{
  FILE *fo;
  fo = fopen ("outdata.txt", "w");	// writing a new file
  if (fo == NULL)
    {
      printf ("File not found.");
    }

  for (counter1 = 1; counter1 < counter; counter1++)
    {
      // printing data into new file
      fprintf (fo, "car%d:%s, the tax on this car is %d\n", counter1,
	       cars[counter1].number, cars[counter1].calculatedtax);
    }
  fclose (fo);			//closing file

  printf ("\n");
  printf ("Press any key to continue\n");
  scanf ("%d", &continu);
  mainmenu ();			// calling main menu
}

int
mainmenu ()
{
  //output data
  printf ("     - Main Menu-\n\n");
  printf ("Press 1 to input file\n");
  printf ("Press 2 to calculate the tax\n");
  printf ("Press 3 to export tax to file\n");
  printf ("Press 4 to exit\n");
  printf ("Enter your choice: ");
  //input data
  scanf ("%d", &choice);

  if (choice == 1)
    {
      inputfiles ();		// calling input files
    }
  if (choice == 2)
    {
      printf ("\n");
      tax ();			// calling tax files
    }
  if (choice == 3)
    {
      outputfiles ();		// calling output files
    }
  if (choice == 4)
    {
      return 0;			// exit program
    }
}

int
main ()				// main function
{
  mainmenu ();
}
