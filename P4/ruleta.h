#ifndef RULETA_H
#define RULETA_H

#include <ctime>
#include <list>
#include <iostream>
#include "jugador.h"
#include "crupier.h"

using namespace std;

class Ruleta{
    private:
        int banca_;                     //dinero en euros que tiene la banca
        int bola_;                      //número entre 0 y 36 que sale en la ruleta en cada jugada
        list<Jugador> jugadores_;       //lista de jugadores
        Crupier crupier_;               //crupier

    public:
    /*esto lo que hace es que ruleta debe recibir un crupier
    y como vamos a usar crupier__ necesitamos inicializarlo,
    para ello le pasamos los valores obligatorios que necesita
    el constructor de crupier desde la variable externa que recibe el contructor ruleta*/
    //NO SE PORQUE NO SE PUEDE PONER LO DE DESPUES DE LOS DOS PUTOS DENTRO DEL CONSTRUCTOR, PERO SEGUN HE LEIDO ES INCORRECTO ademas no compila 
        inline Ruleta(Crupier crupier):crupier_(crupier.getDNI(), crupier.getCodigo()){    //Constructor de la clase Ruleta
            srand(time(NULL));
            bola_=-1;
            banca_=1000000;
        }
        
        inline int getBanca() const {return banca_;}
        inline int getBola() const {return bola_;}
        inline Crupier getCrupier() const {return crupier_;}
        inline list<Jugador> getJugadores() const {return jugadores_;}     //Función observadora de la lista de jugadores

        bool setBanca(int const &banca); //que solo admite valores positivos. En caso contrario devuelve false.
        bool setBola(int const &bola);  //solo admite valores entre 0 y 36. En caso contrario devuelve false.
        inline void setCrupier(Crupier const &crupier) {crupier_=crupier;}

        
        bool addJugador(Jugador const &jugador);

        int deleteJugador(string const &dni);                              //Función que borra a un jugador de la lista pasando un dni como parámetro

        int deleteJugador(Jugador const &jugador);                              //Función que borra a un jugador de la lista pasando un objeto del tipo Jugador como parámetro
        
        void escribeJugadores();
    
        void leeJugadores();

        inline void giraRuleta(){
            bola_= rand()%(37);
        }
       
        void getPremios();

        void getEstadoRuleta(int &njugadores, int &dineroMesa, int &nLanzamientos, int &gananciaBanca);


//////////////////ESTO SON FINCIONES EXTR QUE HA PUEESTO EL DE WUOLAH HACERLO DIFERENTE!!!!!
        bool esRoja(int const &valor);                                          //Funcion que determina si la bola es roja o no
        bool esPar(int const &valor);                                           //Funcion que determina si la bola es par o no
        bool esAlta(int const &valor);                                          //Funcion que determina si la bola es un valor alto o no

};

#endif