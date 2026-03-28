#include <iostream>
#include <iomanip>
#include "person.h"
#include "employee.h"
#include "product.h"
#include "donut.h"

// Lecture activity M02-a
// 1. create another class to inherit from product
// doesn't have to be as complicated as either donut or drink - it could just have one thing, if you'd like
// just ask yourself: what are the properties of this thing you need to know in addition to what's already in product?
// 2. make sure you properly invoke the product constructor
// 3. include a toString() that also calls the product toString()
// 4. create an object for your new class in the main
// 5. print the toString() for your object

int main()
{
   Person p("Harry Potter", 12, "111-2222", "email@aol.com");
   Employee e;
   e.getName();

   std::cout << p.toString() << std::endl;
   std::cout << std::setfill('-');
   std::cout << std::setw(60) << "-" << std::endl;
   std::cout << e.toString() << std::endl;

   product prod(3, "the first product", 3.99, 18);
   donut don;
   drink myDrink(COFFEE, drink::HOT, sizeType::LARGE, "dairy", "flavor");
   std::cout << prod.toString() << std::endl;
   std::cout << don.toString() << std::endl;
   std::cout << myDrink.toString() << std::endl;

   return 0;
}