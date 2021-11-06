//dados.cc
//cuerpo de los métodos de la clase Dados

#include <iostream>
#include <cstdlib> // no lleva .h
#include <ctime> // no lleva .h
#include "dados.h"

Dados::Dados(){
	srand(time(NULL));
	d1_=1;
	d2_=1;
	nd1_=0;
	nd2_=0;
	sum1_=0;
	sum2_=0;
	vect1.assign(5,0); //dimensionamos y ponemos a cero el vector porque en la defiicion de la clase no se puede
	vect2.assign(5,0); //dimensionamos y ponemos a cero el vector porque en la defiicion de la clase no se puede
}

void Dados::lanzamiento(){
	nd1_++;
	nd2_++;
	//genero numeros aleatorios y le sumo 1 porque empieza en el 0
	d1_=(rand()%6)+1;
	d2_=(rand()%6)+1;

	sum1_ += d1_;
	sum2_ += d2_;

	vect1.push_back(d1_);
	vect2.push_back(d2_);
}
//Dado 1
int Dados::getDado1(){
	return d1_;
}

bool Dados::setDado1(int a){
	if((1<=a)&&(a<=6)){
		nd1_++;
		d1_= a;
		sum1_ += d1_;
		vect1.push_back(2);
		return true;
		
	}
	else return false;
}

int Dados::getLanzamientos1(){
	return nd1_;
}

// Dado 2
int Dados::getDado2(){
	return d2_;
}

bool Dados::setDado2(int b){
	if((1<=b)&&(b<=6)){
		nd2_++;
		d2_= b;
		sum2_ += d2_;
		vect2.push_back(b);
		return true;
		
	}
	else return false;
}

int Dados::getLanzamientos2(){
	return nd2_;
}

//operaciones
int Dados::getSuma(){
	return d1_ + d2_;
}

int Dados::getDiferencia(){
	if(d1_>=d2_){
		return d1_-d2_;
	}
	else{
		return d2_-d1_;
	}
}

float Dados::getMedia1(){
	if (nd1_ == 0){
        return 0;
    }
	return (float)sum1_/nd1_; //hay que poner float para que haga bien la operacion
}
float Dados::getMedia2(){
	if (nd2_ == 0){
        return 0;                       
	}
	return (float)sum2_/nd2_; //hay que poner float para que haga bien la operacion
}

void Dados::getUltimos1(int v[]){
	for(int i=0;i<5;i++){
		
		v[i]=vect1[i];
	}
	for(int i=0;i<5;i++){
			printf(" i====%d ",vect1[i]);
		}
}
void Dados::getUltimos2(int v[]){
	for(int i=0;i<5;i++){
		v[i]=vect2[i];
	}
}