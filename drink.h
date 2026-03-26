#ifndef DRINK_H
#define DRINK_H
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "product.h"

// 1st way of making an enum
enum baseType{COFFEE, TEA, CREAM};

// 2nd way of making an enum: this is what LLM's seem to prefer
enum class sizeType{SMALL, MED, LARGE};

class drink : public product
{
public:
   // 3rd way of making an enum
   /* enum class tempType{HOT, ICE, BLEND}; */
   // 4th way of making an enum (unscoped inside a class - burger class enums will be this)
   enum tempType{HOT, ICE, BLEND};
   drink(baseType b, tempType t, sizeType s, std::string dairy, std::string flavor);
   drink(baseType b, tempType t, sizeType s, std::string dairy, std::string flavor, int pn, std::string desc);
   std::string getBaseStr() const;
   std::string getTemperature() const;
   std::string getSize() const;
   std::string getDairy() const;
   std::string getFlavor() const;
   double getPrice() const;
   void setBase(baseType b);
   void setTemperature(tempType t);
   void setSize(sizeType s);
   void setDairy(std::string d);
   void setFlavor(std::string f);
   std::string toString() const;
   const static std::string baseStr[];
   const static std::string tempStr[];
   const static std::string sizeStr[];
   const static baseType bases[];
   const static tempType temps[];
   const static sizeType sizes[];

private:
   baseType base;
   tempType temp;
   sizeType size;
   std::string dairy;
   std::string flavor;
};

#endif