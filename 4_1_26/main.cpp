#include <iostream>
#include <string>
#include <limits>

void resetStream();
int getInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low = 0, int high = 0);
bool isIntInRange(int num, int low, int high);
bool isIntGT0(int num, int = 0, int = 0);

int main()
{
   int guess = getInt("Enter a number between 1 and 100: ", "That is not a number between 1 and 100", isIntInRange, 1, 100);
   std::cout << "You guessed " << guess << std::endl;
   guess = getInt("Enter a number greater than 0 ", "Invalid input", isIntGT0);

   return 0;
}

void resetStream()
{
   std::cout << "You have entered non-numeric data! Please try again!" << std::endl;
   std::cin.clear();
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low, int high)
{
   int num;
   std::cout << prompt;
   std::cin >> num;
   std::cout << std::endl;
   while(!std::cin || !valid(num, low, high)) // checks for input failure or input out of range
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
