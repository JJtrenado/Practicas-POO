#ifndef __jugador__
#define __jugador__
#include "persona.h"        //Incluimos el archivo persona.h para poder realizar la herencia
#include <list>
#include <fstream>
#include <iostream>

using namespace std;

//EStructura apuesta
struct Apuesta{
    int tipo;               //Tipo de apuesta
    std::string valor;      //dependiendo del tipo: numero, color, paridad, alto o bajo
    int cantidad;           //dinero
};

class Jugador:public Persona{
    private:
        int dinero_;
        string codigo_; //codigo del jugador
        list<Apuesta> apuestas_;
    public:
        // Asigna el codigo y pone el dinero a 1000
        inline Jugador(std::string dni, std::string codigo, std::string nombre="", std::string apellidos="", int edad=0, std::string direccion="", std::string localidad ="", std::string provincia="", std::string pais= "", int dinero= 1000):Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais){
            codigo_ = codigo;
            dinero_ = dinero;
        };

        inline void setDinero(int const &dinero){dinero_ = dinero;}
        inline void setCodigo(string const &codigo){codigo_ = codigo;}
        void setApuestas();
        
        inline int getDinero() const { return dinero_;}
        inline string getCodigo() const { return codigo_;}
        inline list<Apuesta> getApuestas() const { return apuestas_;}


};

#endif