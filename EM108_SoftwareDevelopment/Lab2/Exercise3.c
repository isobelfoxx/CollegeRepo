#include <stdio.h>
#include <math.h>

int Euro = 0;
int ans; // whether the human would like to exchange their euro into pounds or dollars.
float amount; // amount of Euro the human has. 
float GBP = 0.693;
float USD = 1.293;

int
main ()
{
  ans = 0;
  // Welcome message.
  printf ("Welcome to Isobel's money converter! :)\n");
  printf ("\n");
  
  // for loop creates a table of numbers (Euro) from 1-10, and then calculates the corresponding values in Pounds and Dollars.
  printf ("Euro   GBP      USD\n");
  for (Euro = 1; Euro < 11; Euro++)
    {
      printf ("%d      ", Euro);
      printf ("%4.2f   ", Euro * GBP);
      printf ("%6.2f\n", Euro * USD);
    }
  printf ("\n");
  // Human inputs their amount of Euro.
  printf ("Please input the amount of Euro you would like to convert!\n");
  scanf ("%f", &amount);
  
  // Human input 1 for pounds or 2 for dollars, the program will only accept these two numbers.
  do
    {
      printf
	("Would you like to Exchange your Euro into Pounds(1) or Dollars(2)?\n");
      scanf ("%d", &ans);
    }
  while (ans != 1 & ans != 2);
  
  //Program tells the human their amount in either Pounds or Dollars.
  if (ans == 1)
    {
      printf ("Your Value in Pounds is %1.2f\n", amount * GBP);
    }
  else
    {
      printf ("Your Value in Dollars is %1.2f\n", amount * USD);
    }
  // Goodbye message.
  printf ("Goodbye! See you again soon!");
  return 0;
}
