#include "clock.h"

clockType::clockType(int h, int m, int s, timeType tt, partType pt)
{
   setTime(h, m, s, tt, pt);
}

void clockType::setTime(int h, int m, int s, timeType tt, partType pt)
{
   hr = h;
   min = m;
   sec = s;
   time = tt;
   part = pt;
}

void clockType::getTime(int & h, int & m, int & s) const
{
   h = hr;
   m = min;
   s = sec;
}

std::string clockType::printTime() const
{
   std::ostringstream out;
   out << std::setfill('0');
   out << std::setw(2) << hr << ":" << std::setw(2) << min << ":" << std::setw(2) << sec;
   if (time == TWELVE)
   {
      if (part == partType::AM)
      {
         out << " AM";
      }
      else
      {
         out << " PM";
      }
   }
   return out.str();
}

void clockType::incrementSeconds()
{
   sec++;
   if (sec == 60)
   {
      sec = 0;
      incrementMinutes();
   }
}

void clockType::incrementMinutes()
{
   min++;
   if (min == 60)
   {
      min = 0;
      incrementHours();
   }
}

void clockType::incrementHours()
{
   hr++;
   if (time == TWENTYFOUR && hr == 24)
   {
      hr = 0;
   }
   else if (time == TWELVE && hr == 12)
   {
      hr = 0;
   }
}
