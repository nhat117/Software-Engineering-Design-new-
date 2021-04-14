#include <iostream>

using namespace std;

class vect {
	private :
		int x;
		int y;
		int z;
	public :
	// constructor
		//Default constructor
		vect () {x = y = z = 0;}
		vect(int a, int b, int c) {
			x = a;
			y = b;
			z = c;
	}
	// Implied operator
	vect operator + (vect ob2);
	void print() {
		cout << x << endl;
		cout << y << endl;
		cout << z << endl;
	}
	//Destructor
	// ~vect();
};

vect vect :: operator + (vect ob2) {
	vect temp;
	temp.x = ob2.x + x;
	temp.y = ob2.y + y;
	temp.z = ob2.z + z;
	return temp;
}

int main(void) {
	vect a(1, 2, 3);
	vect b(2, 2, 2);
	vect c = a + b;
	c.print();
	return 0;
}