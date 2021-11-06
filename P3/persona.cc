#include "persona.h"
#include <string> //fichero de cabecera para cadenas en C++
using namespace std;


Persona::Persona (string dni, string nombre, string apellidos, int edad, string direccion, string localidad, string provincia, string pais){
    dni_=dni;   
    nombre_=nombre;
    apellidos_=apellidos;
    edad_=edad;
    direccion_=direccion;
    localidad_=localidad;
    provincia_=provincia;
    pais_=pais;
}
bool Persona:: setEdad(int edad){ //hay que comprobar que la edad sea mayor o igual que 0
    if (edad>=0){
        edad_=edad;
        return true;
    }
    return false;
}                 

   
bool Persona:: mayor(){ // devuelve true si una persona es mayor de edad y falso en lo contrario
    if(edad_>=18){
        return true;
    }
    return false;
}                   
