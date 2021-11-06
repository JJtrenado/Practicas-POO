#include <iostream>
#include <cstdlib> // no lleva .h
#include <ctime> // no lleva .h

int main(void){
	int i;
	std::cout << "introduce un numero: ";
	std::cin >> i;

	//genero numeros aleatorios y le sumo 1 porque empieza en el 0
	srand(time(NULL));
	int n=(rand()%10)+1;
	std::cout << "n= " << n << "\n";


//
//
//
// hacer un bucle while que haga que lo pregunte hasta que acierte
//
//
//

	if(i<n){
		std::cout << "fallo, introduciste un numero menor \n";
	}
	if(i>n){
		std::cout << "fallo, introduciste un numero mayor \n";	
	}
	if(i==n){
		std::cout << "acierto \n";
	}
}