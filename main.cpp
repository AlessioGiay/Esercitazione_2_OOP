#include <iostream>
using namespace std;

template <typename T>

class NumCompx 
{
	private:
		T real;
		T imag;
		
	public:
		
	NumCompx() : real(0), imag(0) {}  //Default
	NumCompx(T r, T i) : real(r), imag(i) {}  //Parametri
	
	//Coniugato
	NumCompx coniugato() const{ return NumCompx(real,-imag);}
	
	//Parte reale e immaginaria
	T ParteReale() const { return(real);}
	T ParteImmaginaria () const { return(imag);}
};

int main()
{
	NumCompx<double> z1(1.0, 2.0);
	cout<<"Parte reale : "<<z1.ParteReale()<<endl;
	cout<<"Parte immaginaria : "<<z1.ParteImmaginaria()<<endl;
	//cout<<"Coniugato : "<<z1.coniugato()<<endl;
	
	return 0;
}