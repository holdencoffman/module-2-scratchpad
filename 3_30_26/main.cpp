#include <iostream>
#include <cstdlib>
#include <string>
#include "clock.h"

int main()
{
   // There are 3 hardcoded values you can assign to a pointer: 0, nullptr (which is still 0), or the address of an existing variable 
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
   clockType* clockPtr = 0;
   /* std::cout << clockPtr->printTime() << std::endl; */
   (*clockPtr).incrementSeconds(); // need parentheses around the dereferenced pointer for it to work since member access operator would take precedence in order of operations
   clockPtr->incrementSeconds(); // the arrow does the same as parentheses, just a bit more convenient
   /* std::cout << clockPtr->printTime() << std::endl; */

   return 0;
}