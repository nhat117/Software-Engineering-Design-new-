#include <iostream>
using namespace std;

class TwoDShape {
	private :
		float width, height;
	public :
		TwoDShape();
		TwoDShape(float w, float h);
		void showDim();
		void setw (float w);
		void seth (float h);

		float getw();
		float geth();
};