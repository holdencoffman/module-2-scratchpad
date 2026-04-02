#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include "pointers.h"
#include "arrayListType.h"
#include "clock.h"
#include "movieTimes.h"

// M03 - b lab
// look up a currently playing movie
// Create a movieTimes variable for that movie in the main.
// call enterTimes to add the times to the movie
// add the input to a comment
// display the movie

int main()
{
    int guess = getInt("Enter a number between 1 and 100: ", "That is not a number between 1 and 100.", isIntInRange, 1, 100);
    int copy(guess);
    std::cout << "You guessed " << guess << std::endl;
    guess = getInt("Enter a number greater than 0 ", "Invalid input", isIntGT0);
    pointerClass p1(guess);
    p1.addItem(43);
    {
        pointerClass p2(p1);
        p2.addItem(22);
    }
    p1.addItem(236);
    int size = getInt("Please enter the list size between 1 and 10: ", "That is not a valid number.", isIntInRange, 1, 10);
    arrayListType myarray(size);
    for (int i = 0; i < size; i++)
    {
        myarray.insert(rand() % 900 + 1);
    }
    myarray.insert(rand() % 1000 + 900);

    MovieTimes holdensMovie("Project Hail Mary", 166, "PG-13");
    holdensMovie.enterTimes(); // 11:40 AM, 3:05 PM, 6:30 PM, 9:55 PM
    std::cout << holdensMovie.tostring() << std::endl;

    return 0;
}

int getInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low, int high)
{
    int num;
    std::cout << prompt;
    std::cin >> num;
    std::cout << std::endl;
    while (!std::cin || !valid(num, low, high)) //* !std::cin checks for input failure
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << error << std::endl;
        std::cout << prompt;
        std::cin >> num;
        std::cout << std::endl;
    }
    return num;
}

bool isIntInRange(int num, int low, int high)
{
    return num >= low && num <= high;
}

bool isIntGT0(int num, int, int)
{
    return num > 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Clock *makeClock()
{
    Clock *clockptr = nullptr;
    Clock::ClockType type = inputClockType();
    std::string hourPrompt = "Enter the clock's hour: ";
    int hour;
    int min;
    if (type == Clock::TWELVE)
    {
        hour = getInt(hourPrompt, "The hour must be between 1 and 12. ", isIntInRange, 1, 12);
    }
    else
    {
        hour = getInt(hourPrompt, "The hour must be between 0 and 23. ", isIntInRange, 0, 23);
    }
    min = getInt("Enter the clock's minutes: ", "The minutes must be between 0 and 59.", isIntInRange, 0, 59);
    Clock::PartOfDayType part = Clock::PM;
    if (type == Clock::TWELVE)
    {
        part = inputPartOfDay();
    }
    clockptr = new Clock(hour, min, 0, type, part);
    return clockptr;
}

Clock::ClockType inputClockType()
{
    Clock::ClockType time;
    int timeInt = getInt("Is the clock 12 hour or 24 hour? ", "Please enter 12 or 24.", isAorB, 12, 24);
    timeInt = (timeInt / 12) - 1;

    return Clock::formats[timeInt];
}

bool isAorB(int num, int a, int b)
{
    return num == a || num == b;
}

Clock::PartOfDayType inputPartOfDay()
{
    int partInt = -1;
    std::string prompt = "Is it \n1. AM\n2. PM";
    partInt = getInt(prompt, "Please enter 1 or 2.", isAorB, 1, 2);
    return Clock::parts[partInt - 1];
}