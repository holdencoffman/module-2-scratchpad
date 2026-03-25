#include "employee.h"

std::string Employee::toString() const
{
   std::ostringstream out;
   out << Person::toString();
   out << "Salary: " << salary << std::endl;
   out << "Hire Date: " << hireDate << std::endl;
   return out.str();
}