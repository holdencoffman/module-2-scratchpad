#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <sstream>
#include "person.h"

class Employee : public Person
{
public:
   std::string toString() const;

private:
   double salary;
   std::string hireDate;
};







#endif