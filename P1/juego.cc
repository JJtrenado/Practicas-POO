// juego.cc
// Programa principal que prueba el funcionamiento de la calase Dados

#include <iostream>
#include "dados.h"

int main(){
	Dados d;

	int l = 0;
	int i;
	int d1,d2=0;

	while(i != 0){

		std::cout << "\n\n\n";
		std::cout << "0. salir \n";
		std::cout << "1. obtener numero aleatorio \n";
		std::cout << "2. numero dado 1 \n";
		std::cout << "3. numero dado 2 \n";
		std::cout << "4. asignar aleatorio dado 1 \n";
		std::cout << "5. asignar aleatorio dado 2 \n";
		std::cout << "6. suma dados \n";

		std::cout << "introduce un numero \n";
		std::cin >> i;

		switch(i){
			case 1:
				l = d.lanzamiento();
				std::cout << "numero aleatorio:" << l << " \n";
				break;

			case 2:
				d1=d.getDado1();
				if(d1==0){
					std::cout << "el dado 1 no se ha lanzado \n";
				}
				else{
					std::cout << d1 << "\n";
				}
				break;

			case 3:
				d2=d.getDado2();
				if(d2==0){
					std::cout << "el dado 2 no se ha lanzado \n";
				}
				else{
					std::cout << d2 << "\n";
				}
				break;

			case 4:
				if(l==0){
					std::cout << "primero obten un numero aleatorio \n";
				}
				else{
					d.setDado1(l);
					std::cout << "numero aleatorio:" << l << " \n";
				}
				break;

			case 5:
				if(l==0){
					std::cout << "primero obten un numero aleatorio \n";
				}
				else{
					d.setDado2(l);
				}
				break;

			case 6:
				std::cout << d.getSuma() << "\n";
				break;

			default: std::cout << "error \n";
		}
	}
}











///////////////////////////TERMINAAAAR!!