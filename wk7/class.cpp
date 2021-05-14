#include <iostream>

using namespace std;

class cmplx {
	private :
		int real, img;
	public :	
		cmplx () { real = img = 0;}
		cmplx (int i, int j) {real = i,img = j;}
		
		// Getter 
		int Getreal () {return real;}
		int Getimg () {return img;}

		//Class Methode
		void Double();

		//Operator overload
		cmplx operator + (cmplx var);
		cmplx operator - (cmplx var);
		cmplx operator * (cmplx var);

		//Friend function
		friend void Double (cmplx &Ob);
		friend int main(void); 	
};

//Function Prototype
void Double (cmplx & Ob);
ostream & operator << (ostream & stream, cmplx obj);

int main(void) {
	cmplx Ob1 (5, 2);
	cmplx Ob2 (10, 2);
	cout << Ob1 + Ob2;
	cout << Ob1 * Ob2;
	Double (Ob1);
	cout << Ob1;
	return 0;

}

void Double (cmplx & Ob) { // Pass by reference
	Ob.real = Ob.real * 2;
	Ob.img = Ob.img * 2;
}

void cmplx :: Double () { // Has access to a and b
	real = real * 2;
	img = img * 2;
}

cmplx cmplx :: operator - (cmplx var) {
	cmplx tmp;
	tmp.real = this -> real - var.real;
	tmp.img = this -> img - var.img;
	return tmp;
}

cmplx cmplx :: operator * (cmplx var) {
	cmplx tmp;
	tmp.real = this -> real * var.real - (this -> img * var.img);
	tmp.img = this -> real * var.img + (this -> img * var.real) ;
	return tmp;
}

ostream & operator << (ostream & stream, cmplx obj) {
	stream << std :: noshowpos <<obj.Getreal() << std :: showpos << obj.Getimg() << "i" << endl;
	return stream;
}

cmplx cmplx :: operator+(cmplx var) {
	cmplx tmp;
	tmp.real = this -> real + var.real;
	tmp.img = this -> img + var.img;
	return tmp;
}