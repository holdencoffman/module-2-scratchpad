#ifndef PERSON_H
#define PERSON
#include <string>

class Person
{
public:
   Person(std::string n, int a);
   std::string getName();
   void setName(std::string name);
   int getAge();
   void setAge(int a);
   void greet();

private:
   int age;
   std::string name;
   std::string phone;
   std::string email;
};


#endif

















