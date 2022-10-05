#include <stdio.h>

int
main ()
{
  int clientno1;
  int clientno2;
  int clientno3;
  int clientno4;
  int ticketno1;
  int ticketno2;
  int ticketno3;
  int ticketno4;
  int sumtickets;
  int averagetickets;
 
  printf ("Welcome to my Soccer Ticket simulator\n\n");
  
  printf ("Please enter the first client number:");
  scanf ("%d", &clientno1);

  printf ("Please enter the second client number:");
  scanf ("%d", &clientno2);

  printf ("Please enter the third client number:");
  scanf ("%d", &clientno3);

  printf ("Please enter the fourth client number:");
  scanf ("%d", &clientno4);

  printf ("\nPlease enter the first ticket number:");
  scanf ("%d", &ticketno1);

  printf ("Please enter the second ticket number:");
  scanf ("%d", &ticketno2);

  printf ("Please enter the third ticket number:");
  scanf ("%d", &ticketno3);

  printf ("Please enter the fourth ticket number:");
  scanf ("%d", &ticketno4);

  printf ("\nCLIENT NO.");
  printf ("    NO. TICKETS");
  printf ("\n    %d", clientno1);
  printf ("             %d", ticketno1);
  printf ("\n    %d", clientno2);
  printf ("             %d", ticketno2);
  printf ("\n    %d", clientno3);;
  printf ("             %d", ticketno3);
  printf ("\n    %d", clientno4);
  printf ("             %d", ticketno4);

  sumtickets = ticketno1 + ticketno2 + ticketno3 + ticketno4;
  averagetickets = (sumtickets / 4);

  printf ("\n\nThe average numbers of tickets bought by soccer fans is %d",
	  averagetickets);

  return 0;
}
