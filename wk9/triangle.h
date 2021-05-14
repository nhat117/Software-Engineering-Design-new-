#include <iostream>
#include "twodshape.h"

using namespace std;

class Triangle : public TwoDShape {
	private :
	public : 
		Triangle ();
		Triangle (float w, float h) : TwoDShape(w,h){
			cout <<"Parameter";
		};	
		float Area ();
};