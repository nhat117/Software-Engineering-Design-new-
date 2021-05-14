#include <iostream>
#include "triangle.h"

using namespace std;

class BigTriangle : public Triangle {
	public :
		BigTriangle() {
			cout << "Big Triangle" << endl;
		}
		float area();
		int big;
		
};