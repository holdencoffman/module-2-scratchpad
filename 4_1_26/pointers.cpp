#include "pointers.h"

pointerClass::pointerClass(int input)
{
    max = input;
    list = new int[max];
    count = 0;
}

pointerClass::pointerClass(const pointerClass &otherPointerClass)
{
    max = otherPointerClass.max;
    count = otherPointerClass.count;
    list = new int[max]; // start of deep copy
    for (int i = 0; i < count; i++)
    {
        list[i] = otherPointerClass.list[i]; // deep copy each item
    }
}

pointerClass::~pointerClass()
{
    delete[] list;
    list = nullptr;
}

void pointerClass::addItem(int x)
{
    if (count != max)
    {
        list[count] = x;
        count++;
    }
}