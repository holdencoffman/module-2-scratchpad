#ifndef BAGEL_H
#define BAGEL_H
#include <string>
#include <sstream>
#include <iomanip>
#include "product.h"

// Lecture activity M02-a
// 1. create another class to inherit from product
// doesn't have to be as complicated as either donut or drink - it could just have one thing, if you'd like
// just ask yourself: what are the properties of this thing you need to know in addition to what's already in product?
// 2. make sure you properly invoke the product constructor
// 3. include a toString() that also calls the product toString()
// 4. create an object for your new class in the main
// 5. print the toString() for your object

enum bagelType
{
   EVERY,
   SES,
   BLUE,
   RAIS,
   REG
};

enum sideType
{
   CRE,
   LOX,
   SJAM,
   BJAM,
   NONE
};

const std::string bagelStr[] = {"Everything", "Sesame", "Blueberry", "Raisin", "Plain"};
const std::string sideStr[] = {"Cream Cheese", "Smoked Salmon", "Strawberry Jam", "Blueberry Jam", "None"};

class Bagel : public product
{
public:
   // Constructor (providing default values just to make the code more robust)
   Bagel(bagelType b = REG, sideType s = NONE, bool t = false, int q = 1);
   // Getters
   std::string getBagel() const;
   std::string getSide() const;
   std::string getToasted() const;
   double getPrice() const;
   // Setters
   void setBagel(bagelType b);
   void setSide(sideType s);
   void setToasted(bool t);
   // toString()
   std::string toString() const;

private:
   bagelType bagel;
   sideType side;
   bool toasted;
};



#endif