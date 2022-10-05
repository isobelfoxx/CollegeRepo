#include <stdio.h>

float length; 
float depth;
float width; 
float paint; // Amount of litres needed to paint one squared meter.
float volume; 
float sarea; // Surface area of the outside of the basin.

int
main ()
{
  // Welcome message.
  printf ("Hello, I'm here to help you!\n");

  // Human Inputs the dimensions of the basin.
  printf ("Please input the length of the basin in meters:\n");
  scanf ("%f", &length);
  printf ("Please input the depth of the basin in meters:\n");
  scanf ("%f", &depth);
  printf ("Please input the width of the basin in meters:\n");
  scanf ("%f", &width);

  printf ("\n");
  // Human enters the value for the amount of litres needed to paint one squared meter.
  printf
    ("Please input how many litres of paint is required to paint one squared meter:\n");
  scanf ("%f", &paint);
  
  // Calculating the surface area (amount of paint needed), the volume (the amount of water that the basin can hold).
  sarea = (2 * length * width) + ( length * depth) + (2 * depth * width);
  printf
    ("It takes %f Litres of paint to paint the outside of the water basin.\n",
     sarea * paint);

  volume = length * width * depth * 1000;
  printf ("The basin can hold %f Litres of water!\n", volume);

  // Welcome message.
  printf ("Goodbye! See you soon :)\n");
  return 0;
}
