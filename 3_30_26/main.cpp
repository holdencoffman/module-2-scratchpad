#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include "clock.h"

void resetStream();

int main()
{
/*
   // There are 3 harddcoded values you can assign to a pointer: 0, nullptr (which is still 0), or the address of an existing variable 
   int* p = nullptr;
   int q = 7;
   std::cout << &q << std::endl; // This prints the memory address for the integer variable q
   p = &q;

   // dereferencing operator --> * --> this turns a pointer into whatever is at the location it points at

   std::cout << *p << std::endl; // here the outcome is 7 since q is 7 and p is pointing at q's address

   int h = rand() % 24;
   int m = rand() % 60;
   int s = rand() % 60;
   clockType c(h, m, s);
   clockType* clockPtr = nullptr;
   std::cout << "Enter 12 or 24: ";
   std::cin >> h;
   while(!std::cin || (h!=12 && h!=24))
   {
      if (!std::cin)
      {
         resetStream();
      }
      std::cout << "Enter 12 or 24: ";
      std::cin >> h;
   }
   if (h == 12)
   {
      // clockType twelve(rand() % 12 + 1, rand() % 60, rand() % 60, TWELVE); -- can't incrementSeconds out of the if when you do this
      clockPtr = new clockType(rand() % 12 + 1, rand() % 60, rand() % 60, TWELVE); // this puts the clock on heap memory which doesn't go out of scope
   }
   else
   {
      clockPtr = new clockType(rand() % 24, rand() % 60, rand() % 60, TWENTYFOUR);
   }

   (*clockPtr).incrementSeconds();  // this doesn't work because twelve's scope ends after the if
   std::cout << (*clockPtr).printTime() << std::endl;
   // clockType clocks[10];
   */
   int m;
   std::cout << "How many clocks? ";
   std::cin >> m;
   while(!std::cin || m < 1)
   {
      if (!std::cin)
      {
         resetStream();
      }
      std::cout << "Enter at least one clock. " << std::endl;
      std::cout << "How many clocks? ";
      std::cin >> m;
   }
   /*
   clockType* moreClocks = new clockType[m]; // you can't use a non-constant variable to size an array, unless you use a dynamic array. That way the compiler doesn't have to know array size pre-run, since dynamic 
                                             // memory is allocated at runtime (heap memory is controlled at runtime, stack memory is pre-runtime)
   std::cout << moreClocks[m-1].printTime() << std::endl;   // don't need dereferencing operator here because of the way array works, the [] operator is already dereferencing somehow

   // To avoid memory leaks (when runtime memory that got previously allocated cannot be reallocated), you use the delete operator after you're done with a dynamic array
   // Syntax: delete pointerVariable || delete [] pointerVariable <-- for dynamic arrays
   delete clockPtr;
   clockPtr = nullptr; // reinitialize the pointer to nullptr after deleting to avoid dangling pointers
   delete [] moreClocks;
   moreClocks = nullptr;
   moreClocks = new clockType;
   delete moreClocks;
   moreClocks = nullptr;

/*
   // Going to look at dynamic allocation now, using new and delete. This is how you create something without initializing
   {
      clockPtr = new clockType(rand() % 24, rand() % 60, rand() % 60);
   }
   // std::cout << clockPtr->printTime() << std::endl;
   (*clockPtr).incrementSeconds(); // need parentheses around the dereferenced pointer for it to work since member access operator would take precedence in order of operations
   clockPtr->incrementSeconds(); // the arrow does the same as parentheses, just a bit more convenient
   // std::cout << clockPtr->printTime() << std::endl;
*/

// Alright moving on for a sec to look at double pointers

   clockType** moreClocks = new clockType* [m]; // this works now even though there is no default constructor
   for (int i = 0; i < m; ++i)
   {
      if (rand() % 2)
      {
         moreClocks[i] = new clockType(rand() % 12 + 1, rand() % 60, rand() % 60, TWELVE, rand() % 2 ? partType::AM : partType::PM);
      }
   }

   std::cout << (*moreClocks[m-1]).printTime() << std::endl;

   moreClocks = makeClocks(100);
   for (int i = 0; i < 100; ++i)
   {
      delete moreClocks[i];
      moreClocks[i] = nullptr;
   }
   delete [] moreClocks;

   return 0;
}


void resetStream()
{
   std::cout << "You have entered non-numeric data! Please try again!" << std::endl;
   std::cin.clear();
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

clockType** makeClocks(int numClocks)
{
   clockType** clocks = new clockType*[numClocks];
   for (int i = 0; i < numClocks; ++i)
   {
      clocks[i] = new clockType(0, 0, 0);
   }
   return clocks;
}