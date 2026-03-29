// Main purpose here is to tackle input functions and INPUT VALIDATION
// I didn't have access to the demo code for the clock class she was using so matched it as best I could

#include <iostream>
#include <limits>
#include "clock.h"
#include <cstdlib>

/*
C++ Random Number Guide:

If you want a number between 0 and N
val = rand() % (N+1)

If you want a number with a range M...N
val = rand() % (N+1-M) + M

To make the seed different every runtime:
srand(time(NULL))
*/

timeType inputTimeType();
partType inputPartOfDay();
int inputHour(timeType);
int inputMinuteOrSecond(std::string);
void resetStream();
clockType generateClock();

int main()
{
   srand(time(NULL));
   int numClocks = 0;
   std::cout << "How many clocks do you want to make? ";
   std::cin >> numClocks;
   std::cout << std::endl;
   while (!std::cin || numClocks < 0)
   {
      if (!std::cin)
      {
         resetStream();
      }
      std::cout << "Please enter a number greater than 0." << std::endl;
      std::cout << "How many clocks do you want to make? ";
      std::cin >> numClocks;
      std::cout << std::endl;
   }
   for (int i = 0; i < numClocks; ++i)
   {
   timeType time = inputTimeType();
   int hour = inputHour(time);
   int min = inputMinuteOrSecond("minutes");
   int sec = inputMinuteOrSecond("seconds");
   partType partOfDay = partType::PM;
   if (time == TWELVE)
   {
      partOfDay = inputPartOfDay();
   }
   clockType myClock(hour, min, sec, time, partOfDay);
   std::cout << myClock.printTime() << std::endl;
   }
   clockType c = generateClock();
   std::cout << c.printTime() << std::endl;
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

partType inputPartOfDay()
{
   int partInt = -1;
   std::cout << "Is it " << std::endl;
   for (int i = 0; i < 2; ++i)
   {
      std::cout << i + 1 << ". " << partToStr[i] << std::endl;
   }
   std::cin >> partInt;
   while (!std::cin || partInt < 1 || partInt > 2)
   {
      if (!std::cin)
      {
         resetStream();
      }
      std::cout << "Is it " << std::endl;
      for (int i = 0; i < 2; ++i)
      {
         std::cout << i + 1 << ". " << partToStr[i] << std::endl;
      }
      std::cin >> partInt;
   }

   return parts[partInt - 1];
}

int inputHour(timeType tt)
{
   int hour;
   std::cout << "Enter the hour on the clock: ";
   std::cin >> hour;
   std::cout << std::endl;
   while (!std::cin || (tt == TWELVE && hour < 1) || (tt == TWELVE && hour > 12) || hour < 0 || hour > 23)
   {
      if (!std::cin)
      {
         resetStream();
      }
      if (tt == TWELVE)  
      {
         std::cout << "Please enter a number between 1 and 12. " << std::endl;
      }
      else
      {
         std::cout << "Please enter a number between 0 and 23. " << std::endl;
      }
      std::cout << "Enter the hour on the clock: ";
      std::cin >> hour;
      std::cout << std::endl;
   }
   return hour;
}

int inputMinuteOrSecond(std::string prompt)
{
   int mOrS;
   std::cout << "Enter the " << prompt << " on the clock: ";
   std::cin >> mOrS;
   std::cout << std::endl;
   while (!std::cin || mOrS < 0 || mOrS > 59)
   {
      if (!std::cin)
      {
         resetStream();
      }
      std::cout << "Please enter a number between 0 and 59. " << std::endl;
      std::cout << "Enter the " << prompt << " on the clock: ";
      std::cin >> mOrS;
      std::cout << std::endl;
   }
   return mOrS;
}

void resetStream()
{
   std::cout << "You have entered non-numeric data! Please try again!" << std::endl;
   std::cin.clear();
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

clockType generateClock()
{
   timeType tt;
   partType pt = partType::PM;
   int hour = 0;
   int min = 0;
   int sec = 0;
   int r = rand() % 2 + 1;
   tt = static_cast<timeType>(r * 12);
   if (tt == TWELVE)
   {
      hour = rand() % 12 + 1;
      r = rand() % 2;
      pt = parts[r];
   }
   else
   {
      hour = rand() % 24;
   }
   min = rand() % 60;
   sec = rand() % 60;

   return clockType(hour, min, sec, tt, pt);
}
