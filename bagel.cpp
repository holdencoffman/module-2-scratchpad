#include "bagel.h"

Bagel::Bagel(bagelType b, sideType s, bool t, int q) : product(34, "bagel", 1)
{
   setBagel(b);
   setSide(s);
   setToasted(t);
   setQuantity(q);
   setPrice(getPrice());
}

std::string Bagel::getBagel() const
{
   return bagelStr[bagel];
}

std::string Bagel::getSide() const
{
   return sideStr[side];
}

std::string Bagel::getToasted() const
{
   std::string returnStr;
   if (toasted)
   {
      returnStr = "Toasted";
   }
   else
   {
      returnStr = "Not Toasted";
   }
   return returnStr;
}

// getPrice() algorithm defined here, taking the opportunity to practice the switch statement control structure - didn't use it too much in CS1
double Bagel::getPrice() const
{
   double returnPrice = 2;

   // Pricing component for the type of bagel
   switch (bagel)
   {
   case EVERY:
      returnPrice += 0.25;
      break;
   case SES:
      returnPrice += 0.25;
      break;
   case BLUE:
      returnPrice += 0.25;
      break;
   case RAIS:
      returnPrice += 0.25;
      break;
   case REG:
      break;
   }

   // Pricing component for the type of side
   switch (bagel)
   {
   case CRE:
      returnPrice += 0.50;
      break;
   case LOX:
      returnPrice += 2.50;
      break;
   case SJAM:
      returnPrice += 0.50;
      break;
   case BJAM:
      returnPrice += 0.50;
      break;
   case NONE:
      break;
   }

   return returnPrice * getQuantity();
}

void Bagel::setBagel(bagelType b)
{
   bagel = b;
}

void Bagel::setSide(sideType s)
{
   side = s;
}

void Bagel::setToasted(bool t)
{
   toasted = t;
}

std::string Bagel::toString() const
{
   std::ostringstream out;
   out << std::setprecision(2) << std::fixed << std::showpoint;
   out << product::toString() << std::endl;
   out << "Bagel: " << getBagel() << std::endl;
   out << "Side: " << getSide() << std::endl;
   out << "Toasted? - " << getToasted() << std::endl;
   out << "Price: $" << product::getPrice() << std::endl;

   return out.str();
}
