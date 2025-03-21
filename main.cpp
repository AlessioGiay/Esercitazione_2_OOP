#include <iostream>
#include <iomanip>

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
	NumCompx coniugato() const{ 
		return NumCompx(real,-imag);}
	
	//Parte reale e immaginaria
	T ParteReale() const { 
		return(real);}
	T ParteImmaginaria () const { 
		return(imag);}
	
	//Overload +
	NumCompx operator+(const NumCompx& other) {
		return NumCompx(real + other.real, imag + other.imag);}

	//Overload *
	NumCompx operator*(const NumCompx& other) {
		return NumCompx(real * other.real - imag * other.imag,
			   			real * other.imag + imag * other.real);}
			  
	//Overload +=
	NumCompx operator+=(const NumCompx& other) {
		real += other.real;
		imag += other.imag;
		return *this;}
		
	//Overload *=
	NumCompx operator*=(const NumCompx& other) {
		T NewR = real * other.real - imag * other.imag;
		T NewI = real * other.imag + imag * other.real;
		real = NewR;
		imag = NewI;
		return *this;}
			 
	// Overload dell'operatore <<
    friend std::ostream& operator<<(std::ostream& os, const NumCompx& c) {
        os << c.real;
        if (c.imag >= 0)
            os << "+" << c.imag << "i";
        else
            os << c.imag << "i";
        return os;
    }
};

int main()
{	
	NumCompx<double> z1(1.0, 2.0);
	NumCompx<double> z2(3.3, 1.9);

    std::cout << std::fixed << std::setprecision(1);
    
	std::cout << "z1: " << z1 << "\n";
	std::cout<<"Parte reale : "<<z1.ParteReale()<<std::endl;
	std::cout<<"Parte immaginaria : "<<z1.ParteImmaginaria()<<std::endl;
	std::cout<<"Coniugato : "<<z1.coniugato()<<std::endl;	
	
	NumCompx<double> sum = z1 + z2;
    NumCompx<double> product = z1 * z2;
	NumCompx<double> Rsum = z1 += z2;
	NumCompx<double> Rproduct = z1 *= z2;
	
    std::cout << "z2: " << z2 << "\n";
    std::cout << "Somma: " << sum << "\n";
    std::cout << "Prodotto: " << product << "\n";
    std::cout << "Somma +=: " << Rsum << "\n";
    std::cout << "Prodotto *=: " << Rproduct <<"\t\"Ora z1 vale " << Rsum << "\"\n";	
	
	return 0;
}