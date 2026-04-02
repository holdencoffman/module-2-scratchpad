#ifndef ARRAY_H
#define ARRAY_H
#include <string>

class arrayListType
{
public:
   arrayListType(int = 100);
   arrayListType(const arrayListType &);
   ~arrayListType();
   std::string toString() const;
   bool isEmpty() const;
   int listSize() const;
   int maxListSize() const;
   bool isItemAtEqual(int, int) const;
   void insert(int);
   int at(int) const;

protected:
   int* list;
   int length;
   int maxSize;
};


#endif