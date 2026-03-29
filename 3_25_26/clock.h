#ifndef CLOCK_H
#define CLOCK_H
#include <string>
#include <sstream>
#include <iomanip>

enum timeType
{
   TWELVE = 12,
   TWENTYFOUR = 24
};

enum class partType
{
   AM = 4,
   PM = 8
};

const partType parts[2] = {partType::AM, partType::PM};
const std::string partToStr[2] = {"AM", "PM"};
const timeType formats[2] = {TWELVE, TWENTYFOUR};

class clockType
{
public:
   clockType(int, int = 0, int = 0, timeType = TWENTYFOUR, partType = partType::PM);
   void setTime(int, int, int, timeType, partType);
   void getTime(int&, int&, int&) const;
   std::string printTime() const;
   void incrementSeconds();
   void incrementMinutes();
   void incrementHours();

   // couldn't see past here yet

   void setHour(int);
   void setMinute(int);
   void setSecond(int);
   void getTime(int &, int &, int &) const;
   int getHour() const;
   int getMinute() const;
   int getSecond() const;
   std::string printTime() const;
   void incrementSeconds();
   void incrementMinutes();
   void incrementHours();
   bool equalTime(const Clock &) const;
   void clockTick();

private:
   int hr;
   int min;
   int sec;
};

#endif