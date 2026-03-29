// Main purpose here is to tackle input functions and INPUT VALIDATION
// I didn't have access to the demo code for the clock class she was using so matched it as best I could

#include <iostream>
#include <limits>
#include "clock.h"

timeType inputTimeType();
partType inputPartOfDay();
int inputHour(timeType);
int inputMinuteOrSecond(std::string);
void resetStream();

int main()
{
   timeType time = inputTimeType();
   /*int hour = inputHour(time);
   int min = inputMinuteOrSecond("minutes");
   int sec = inputMinuteOrSecond("seconds");
   partType partOfDay = partType::PM;
   if (time == TWELVE)
   {
      partOfDay = inputPartOfDay();
   }
   clockType myClock(hour, min, sec, time, partOfDay);
   std::cout << myClock.printTime() << std::endl; */


   return 0;
}

timeType inputTimeType()
{
   int timeInt;
/* std::cout << "Is the clock " << std::endl;
   std::cout << "1. Twelve Hour" << std::endl;
   std::cout << "2. Twenty-Four Hour" << std::endl; */
   std::cout << "Is the clock 12 hour or 24 hour? ";
   std::cin >> timeInt;
   while (!std::cin || (timeInt != 12 && timeInt != 24))
   {
      if (!std::cin)
      {
         resetStream();
      }
      std::cout << "Please enter 12 or 24." << std::endl;
      std::cout << "Is the clock 12 hour or 24 hour? ";
      std::cin >> timeInt;
   }

   timeInt = (timeInt / 12) - 1;

   return formats[timeInt];
}

void resetStream()
{
   std::cout << "You have entered non-numeric data! Please try again!" << std::endl;
   std::cin.clear();
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}