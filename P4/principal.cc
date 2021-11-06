#include "ruleta.h"

using namespace std;
int main(){
    int menu_;
    Crupier crupier_();
    Ruleta ruleta_(crupier_);

    while(menu_!=7){
        cout<<"1 Cargar los jugadores del fichero jugadores.txt";
        cout<<"2 Guardar los jugadores en jugadores.txt";
        cout<<"3 Ver el estado de la ruleta, el dinero de la banca y el de los jugadores.";
        cout<<"4 Hacer girar la ruleta mostrando el número que ha salido, los premios de cada jugador y lo que gana/pierde la banca";
        cout<<"5 Eliminar un jugador de la mesa";
        cout<<"6 Añadir un jugador a la mesa";
        cout<<"7 Salir del programa";

        cin>>menu_;
    }

    switch (menu_){
    case 1:

        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    
    default:
        break;
    }
}