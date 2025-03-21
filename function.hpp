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
};
			 
// Overload dell'operatore <<
template<typename T>
std::ostream& operator<<(std::ostream& out, const NumCompx<T>& z) {
	out<<z.ParteReale();
    if (z.ParteImmaginaria() >= 0) {
        out << "+" << z.ParteImmaginaria() << "i";}
    else {
        out << z.ParteImmaginaria() << "i";}
    return out; }