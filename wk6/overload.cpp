#include <iostream>

using namespace std;

class Cmplx {
	private :
		//Encapsulation
		int Rez;
		int Img;
	public :
		Cmplx () {
			Rez = 0;
			Img = 0;
		}
		// Constructor
		Cmplx (int a, int b) {
			Rez = a;
			Img = b;
		}
		//Constructor Overload
		Cmplx(int a) {
			Rez = a;
			Img = 0;
		}

		// Getter and setter (using inline inline function)
		inline int getImg() {return Img; }
		inline int getRez() {return Rez;}
		// Setter
		void setImg (int a) {Img = a;}
		void setRez (int b) {Rez = b;}

		//Operator Overload
		
		Cmplx operator + (Cmplx a) {
			Cmplx tmp;
			tmp.Rez = this -> Rez + a.Rez;
			tmp.Img = this -> Img + a.Img;
			return tmp;
		}

		Cmplx operator - (Cmplx a) {
			Cmplx tmp;
			tmp.Rez = this -> Rez - a.Rez;
			tmp.Img = this -> Img - a.Img;
			return tmp;
		}

		//Friend Function
		friend ostream & operator << (ostream & output, Cmplx &a);
		friend istream & operator >> (istream & input, Cmplx &a);
		friend Cmplx operator + (int a, Cmplx b);
		
};	
// Overload stream operator
//Overload Out stream
ostream & operator << (ostream & output, Cmplx &a) {
	output << std :: noshowpos << a.getRez() << std :: showpos << a.getImg() << "i" << std :: noshowpos;
	return output;
}
//Overload instream
istream & operator >> (istream & input, Cmplx &a) {
	input >> a.Rez >> a.Img;
	return input;
}

Cmplx operator + (int a, Cmplx b) {
	Cmplx tmp;
	tmp.Rez = b.Rez + a;
	tmp.Img = b.Img;
	return tmp;
}
 
int main(void) {
	Cmplx o1, o2, o3;
	int a, b;
	cout << "Enter the real part and imagine part: ";
	//Using Overloading operator
	cin >> o1;
	cout << o1 << endl;
	o2 = 10 + o1;
	o3 = o2 + o1;
	cout << o1 << " + " << 10 << " = " << o2 <<  endl;
	cout << o2 << " + " << o1 << " = " << o3 << endl;
	return 0;
}