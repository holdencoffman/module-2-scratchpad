#include "arrayListType.h"

arrayListType::arrayListType(int m)
{
   if (m < 1)
   {
      m = 1;
   }
   maxSize = m;
   list = new int[maxSize];
   length = 0;
}

arrayListType::arrayListType(const arrayListType & other)
{
   maxSize = other.maxSize;
   length = other.length;
   list = new int[maxSize];
   for (int i = 0; i < length; ++i)
   {
      list[i] = other.list[i];
   }
}

arrayListType::~arrayListType()
{
   delete [] list;
   list = nullptr;
}

std::string arrayListType::toString() const
{
   std::string out;
   out += std::to_string(list[0]);
   for (int i = 1; i < length; ++i)
   {
      out += ", " + std::to_string(list[i]);
   }
   return out;
}

bool arrayListType::isEmpty() const
{
   return length == 0;
}

int arrayListType::listSize() const
{
   return length;
}

int arrayListType::maxListSize() const
{
   return maxSize;
}

bool arrayListType::isItemAtEqual(int index, int value) const
{
   if (index < length)
   {
      return list[index] == value;
   }
   else
   {
      return false;
   }
}

void arrayListType::insert(int value)
{
   if (length == maxSize)
   {
      int* temp = list;
      maxSize++;
      list = new int[maxSize];
      for (int i = 0; i < length; ++i)
      {
         list[i] = temp[i];
      }
   }
   list[length] = value;
   length++;
}

int arrayListType::at(int index) const
{
   if (index < length)
   {
      return list[index];
   }
   else
   {
      return 0;
   }
}
