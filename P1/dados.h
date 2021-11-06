// dados.h
// La clase dados representa el lanzamiento de dos dados
#ifndef __dados__
#define __dados__

#include <iostream>
#include <vector>

using namespace std;

class Dados{
private:
	int d1_;						// valor dado 1
	int d2_;						// valor dado 2
	int nd1_;						// numero de lanzamientos dado 1
	int nd2_;						// numero de lanzamientos dado 2
	int sum1_;						// suma de los valores del dado 1
	int sum2_;						// suma de los valores del dado 2
	
	//a los vectores no se les puede dar el tamaño dentro de la clase
	vector <int> vect1;	// vector del dado 1
	vector <int> vect2;	// vector del dado 2

public:
	Dados();					// el constructor no devuelve nada
	void lanzamiento(); 		// obtiene un nuevo valor aleatorio para los dados
	int getDado1();				// devuelve el valor del primer dado
	int getDado2();				// devuelve el valor del segundo dado
	bool setDado1(int a);		// recibe un entero como único parámetro, y lo asigna al dado 1 si dicho entero está entre 1 y 6, en cuyo caso devuelve true. En caso contrario no lo asigna y devuelve false
	bool setDado2(int b);		// igual
	int getSuma();				// devuelve el valor de la suma de los dos dados
	int getLanzamientos1();		// devuelve el numero de veces que se ha lanzado el dado 1
	int getLanzamientos2();		// devuelve el numero de veces que se ha lanzado el dado 2
	int getDiferencia();		// devuelve un entero con la distancia entre el menor y el mayor valor de los almacenados en los dados
	float getMedia2();			// calcula la media del dado 2
	float getMedia1();			// calcula la media del dado 1
	void getUltimos1(int v[]);  // Guarda en v[] los ultimos 5 valores del dado 1
	void getUltimos2(int v[]);  // Guarda en v[] los ultimos 5 valores del dado 2

};

#endif