#ifndef PERSONA_H
#define PERSONA_H

#include <string> //fichero de cabecera para cadenas en C++
using namespace std;


class Persona{
    private:
        string dni_;
        string nombre_;
        string apellidos_;
        int edad_=0;
        string direccion_;
        string localidad_;
        string provincia_;
        string pais_;

    public:
        // dni es parametro obligatorio y los demas son opcionales
        Persona (string dni, string nombre="", string apellidos="", int edad=0, string direccion="", string localidad ="", string provincia="", string pais= "");
        
        inline void setDNI(string const &dni) {dni_=dni;}                               // se pone const para que no se pueda modificar esa variable
        inline string getDNI() const {return dni_;}                                     // al llevar const es como si fuera de solo lectura

        inline void setNombre(string const &nombre) {nombre_=nombre;}
        inline string getNombre() const {return nombre_;}

        inline void setApellidos(string const &apellidos) {apellidos_=apellidos;}
        inline string getApellidos() const {return apellidos_;}

        bool setEdad(int edad);                                                         // hay que comprobar que la edad sea mayor o igual que 0
        inline int getEdad() const {return edad_;}

        inline void setDireccion(string const &direccion) {direccion_=direccion;}
        inline string getDireccion() const {return direccion_;}

        inline void setLocalidad(string const &localidad) {localidad_=localidad;}
        inline string getLocalidad() const {return localidad_;}

        inline void setProvincia(string const &provincia) {provincia_=provincia;}
        inline string getProvincia() const {return provincia_;}

        inline void setPais(string const &pais) {pais_=pais;}
        inline string getPais() const {return pais_;}

        inline string getApellidosyNombre() const {return apellidos_ + ", " + nombre_;} // devuelve un string con el formato: “apellidos, nombre” (observa que hay una coma y detrás un espacio entre los apellidos y el nombre). Usar la concatenación (operador+) de la clase string.
        
        bool mayor();                                                                   // devuelve true si una persona es mayor de edad y falso en lo contrario
};


#endif