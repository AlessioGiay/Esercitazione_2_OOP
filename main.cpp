#include <iostream>
#include <iomanip>
#include "function.hpp"

int main()
{	
	NumCompx<double> z1(1.0, -2.0);
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