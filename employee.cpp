#include "employee.h"

Employee::Employee() : Person("Harry Potter", 12, "555-1212", "hpotter@aol.com")
{
}

Employee::Employee(std::string n, int a, std::string p, std::string e, double s, std::string h) : Person(n, a, p, e)
{
   setSalary(s);
   setHireDate(h);
}

void Employee::setSalary(double s)
{
}

void Employee::setHireDate(std::string h)
{
}

double Employee::getSalary() const
{
   return 0.0;
}

std::string Employee::getHireDate() const
{
   return std::string();
}

std::string Employee::toString() const
{
   std::ostringstream out;
   out << Person::toString();
   out << "Salary: " << salary << std::endl;
   out << "Hire Date: " << hireDate << std::endl;
   return out.str();
}