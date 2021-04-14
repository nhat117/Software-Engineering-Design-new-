#include <iostream>

using namespace std;

class cmplx {
	private :
		int rez, im;
	public :
	//Constructor
	cmplx() {rez = im = 0;}
	
	cmplx(int a, int b) {
		rez = a;
		im = b;
	}
	friend void print(cmplx a);
	cmplx operator + (cmplx b);
};

//friend function
void print(cmplx a) {
	cout << a.rez << " + " << a.im << "i";
};

// Operator overload
cmplx cmplx :: operator+(cmplx b) {
	cmplx tmp;
	tmp.rez = rez + b.rez;
	tmp.im = im + b.im;
	return tmp;
}


int main(void) {
	cmplx a (1, 2);
	cmplx b (2, 3);
	cmplx c = a + b;
	print(c);
	return 0;
}