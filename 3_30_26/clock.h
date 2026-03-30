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
   clockType(int = 0, int = 0, int = 0, timeType = TWENTYFOUR, partType = partType::AM);
   void setTime(int, int, int, timeType, partType);
   void getTime(int&, int&, int&) const;
   std::string printTime() const;
   void incrementSeconds();
   void incrementMinutes();
   void incrementHours();

   // couldn't see past here yet

private:
   int hr;
   int min;
   int sec;
   timeType time;
   partType part;
};

#endif