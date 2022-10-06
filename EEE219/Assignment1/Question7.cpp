Question 7

#include <iostream>

using namespace std;

void
printMemory (int mem[], int size)
{
  // prints 
  cout << "Address            Contents" << endl;
  for (int count = 0; count < size; ++count)
    {
        // changes the memory adress from hex to decimal and 
       // prints memory adress and the corresponding array value 
      cout << reinterpret_cast < uintptr_t >
	(&mem[count]) << "     " << mem[count] << endl;

    }
}

int
main ()
{
  int mem[] = { 3, 4, 6, 22, 100, 2, 1 };
  // calls function
  printMemory (mem, 7);
  return 0;
}
