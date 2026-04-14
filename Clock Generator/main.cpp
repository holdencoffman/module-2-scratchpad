#include <iostream>
#include <cstdlib>

int main()
{
    std::cout << "10" << std::endl;

    for (int i = 0; i < 10; ++i)
    {
        int twelveOrTwentyFour = ((rand() % 2) + 1) * 12;

        int hour;
        if (twelveOrTwentyFour == 12)
            hour = (rand() % 12) + 1;
        
        else if (twelveOrTwentyFour == 24)
            hour = rand() % 24;
        
        int minutes = rand() % 60;
        std::cout << twelveOrTwentyFour << std::endl << hour << std::endl << minutes << std::endl;

        if (twelveOrTwentyFour == 12)
            std::cout << (rand() % 2) + 1 << std::endl;
            
    }

    return 0; 
}