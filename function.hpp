#pragma once

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
    /*std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
    os << c.getReal();
    if (c.getImag() >= 0)
        os << "+" << c.getImag() << "i";
    else
        os << c.getImag() << "i";
    return os;
}*/

    /*Overload of <<, to make the rationals printable
	template<typename I>
	std::ostream&
	operator<<(std::ostream& os, const rational<I>& r) {
    if (r.den() != 1)
        os << r.num() << "/" << r.den();
    else
        os << r.num();

    return os;
}*/
};
