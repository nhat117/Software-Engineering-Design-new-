#include "twodshape.h"
#include <iostream>

using namespace std;

class Triangle : public TwoDShape {
	private :
	public : 
		Triangle () {
			cout<<"Triangle Default"<< endl;
		}

		Triangle (float width, float height) : TwoDShape(width, height) {
			// this -> setw(width);
			// this -> seth(height);
			cout << "Triangle parameter" << endl;
		}
		char style[20];
		float area ();
};