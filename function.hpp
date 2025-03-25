#pragma once
template <typename T>

class NumCompx 
{
	private:
		T real;
		T imag;
		
	public:
	
    explicit NumCompx(T a)
    {
        real=a, imag=0.0;
        std::cout<<"\nIl numero "<<a<<" è stato convertito in formato complesso"<<std::endl;
    }
	
	//Costruttori	
	NumCompx() : real(0), imag(0) {}  //Default
	NumCompx(T r, T i) : real(r), imag(i) {}  //Parametri
	
	//Coniugato
	NumCompx coniugato() 
	const{ 
		return NumCompx(real,-imag);
	}
	
	//Parte reale e immaginaria
	T ParteReale() const 
	{ 
		return(real);
	}
	T ParteImmaginaria () const 
	{ 
		return(imag);
	}
	
	//Overload + fra complessi
	NumCompx operator+(const NumCompx& other) 
	{
		return NumCompx(real + other.real, imag + other.imag);
	}

	//Overload * fra complessi
	NumCompx operator*(const NumCompx& other) 
	{
		return NumCompx(real * other.real - imag * other.imag,
			   			real * other.imag + imag * other.real);
	}
			  
	//Overload += fra complessi
	NumCompx& operator+=(const NumCompx& other) 
	{
		real += other.real;
		imag += other.imag;
		return *this;
	}
		
	//Overload *= fra complessi
	NumCompx& operator*=(const NumCompx& other) 
	{
		T NewR = real * other.real - imag * other.imag;
		T NewI = real * other.imag + imag * other.real;
		real = NewR;
		imag = NewI;
		return *this;
	}
		
	//Overload + Complesso-Altro
	NumCompx operator+(const T& n) 
	{
		return NumCompx(real + n, imag);
	}
		
	//Overload * Complesso-Altro
	NumCompx operator*(const T& n) 
	{
		return NumCompx(real * n, imag * n);
	}
};
			 
// Overload dell'operatore <<
template<typename T>
std::ostream& operator<<(std::ostream& out, const NumCompx<T>& z) 
{
	if (z.ParteReale()==0.0 && z.ParteImmaginaria()!=0.0)
	{
		out << z.ParteImmaginaria() << "i";
	}
	else if (z.ParteReale()!=0.0 && z.ParteImmaginaria()==0.0)
	{
		out<<z.ParteReale();
	}
	else if (z.ParteReale()==0.0 && z.ParteImmaginaria()==0.0)
	{
		out<<z.ParteReale();
	}
	else
	{
		out<<z.ParteReale();
        if (z.ParteImmaginaria() >= 0) {
            out << "+" << z.ParteImmaginaria() << "i";}
        else {
            out << z.ParteImmaginaria() << "i";}
    }
    return out; 
}

//Overload + Altro-Complesso
template<typename T>
NumCompx<T> operator+(const T n, const NumCompx<T>& z) 
{
    return NumCompx<T>(z.ParteReale() + n, z.ParteImmaginaria());
}
    
//Overload * Altro-Complesso
template<typename T>
NumCompx<T> operator*(const T n, const NumCompx<T>& z) 
{
	return NumCompx<T>(z.ParteReale() * n, z.ParteImmaginaria() * n);
}