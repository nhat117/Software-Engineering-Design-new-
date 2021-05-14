#include <iostream>
using namespace std;
class TwoDShape
{
	private: // nothing for the moment
		float width, height;
	public:
   TwoDShape() {
     cout << "TwoDShape Default" << endl;
    this -> width = 0;
    this -> height = 0;
   }

   TwoDShape(float width, float heigh)
   {
     cout << "TwoDShape with parameter" << endl;
     this->width = width;
     this->height = height;
   }

   void showDim();
   void setw(float w) { width  = w;   }
   void seth(float h) { height = h;   }
   float getw()       { return width; }
   float geth()       { return height;}
};