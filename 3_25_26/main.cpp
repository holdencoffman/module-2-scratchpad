#include <iostream>
#include <cstdlib>
#include <limits>
#include "clock.h"
#include "drink.h"

void clockTick(int &h, int &m, int &s);
Clock makeClock();
void resetStream();
void promptDrinkSize();
void promptDrinkBase();
void promptDrinkTemp();

int main()
{
    Clock c(6, 9, 0);
    Clock d(12);
    d = c;
    Clock clocks[100];

    // c.clockTick();
    int hr = 23;
    int min = 59;
    int sec = 59;
    c.getTime(hr, min, sec);
    // clockTick(hr, min, sec);
    std::cout << c.printTime() << std::endl;
    if (c.equalTime(d))
    {
        std::cout << "The clocks are the same" << std::endl;
    }
    for (int i = 0; i < 100; i++)
    {
        clocks[i] = makeClock();
        std::cout << clocks[i].printTime() << std::endl;
    }
    int sizeInt;
    int baseInt;
    int tempInt;
    std::string dairy;
    std::string flavor;
    promptDrinkBase();
    std::cin >> baseInt;
    while (!std::cin || baseInt < 1 || baseInt > 3)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "You must choose a number from the list." << std::endl;
        promptDrinkBase();
        std::cin >> baseInt;
    }
    promptDrinkSize();
    std::cin >> sizeInt;
    while (!std::cin || sizeInt < 1 || sizeInt > 3)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "You must choose a number from the list." << std::endl;
        promptDrinkSize();
        std::cin >> sizeInt;
    }
    promptDrinkTemp();
    std::cin >> tempInt;
    while (!std::cin || tempInt < 1 || tempInt > 3)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "You must choose a number from the list." << std::endl;
        promptDrinkTemp();
        std::cin >> tempInt;
    }
    std::cout << "Please enter a flavor for your drink: ";
    std::getline(std::cin, flavor);
    std::cout << "What kind of dairy would you like? ";
    std::cin >> std::ws;
    std::getline(std::cin, dairy);
    // drink myDrink(COFFEE, drink::HOT, sizeType::LARGE, dairy, flavor);
    drink cusDrink(drink::bases[baseInt - 1], drink::temps[tempInt - 1], drink::sizes[sizeInt - 1], dairy, flavor);
    std::cout << cusDrink.toString() << std::endl;
    return 0;
}

void clockTick(int &h, int &m, int &s)
{
    s++;
    if (s == 60)
    {
        s = 0;
        m++;
        if (m == 60)
        {
            m = 0;
            h++;
            if (h == 24)
            {
                h = 0;
            }
        }
    }
}

Clock makeClock()
{
    static int numClocks = 0;
    int hr = rand() % 24;
    int min = rand() % 60;
    int sec = rand() % 60;
    Clock returnClock(hr, min, sec);
    numClocks++;
    return returnClock;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void promptDrinkSize()
{
    std::cout << "Please choose the drink size: " << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << i + 1 << ": " << drink::sizeStr[i] << std::endl;
    }
}

void promptDrinkBase()
{
    std::cout << "Please choose the drink base: " << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << i + 1 << ": " << drink::baseStr[i] << std::endl;
    }
}

void promptDrinkTemp()
{
    std::cout << "Please choose the drink temperature: " << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << i + 1 << ": " << drink::tempStr[i] << std::endl;
    }
}