#include "ruleta.h"
#include "jugador.h"    //Incluimos jugador.h para poder declarar objetos de la clase Jugador
#include "crupier.h"    //Incluimos crupier.h para poder declarar objetos de la clase Crupier
#include "persona.h"

using namespace std;

int main(){
    int menu_;                                      //opcion del menu
    string dniCrupier_;
    string nombreCrupier_;
    Crupier crupier_("1234567", "crupier1");
    Ruleta ruleta_(crupier_);

    int nJugadores_, nLanzamientos_, dineroMesa_, ganaciaBanca_; //variables pra guardar el estado de la ruleta

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
    cout<<"dime el DNI del crupier";
    cin>>dniCrupier_;
    cout<<"dime el nombre del crupier";
    cin>>nombreCrupier_;
    
    switch (menu_){
        case 1:
            ruleta_.leeJugadores();
            cout<<"jugadores del fichero jugadores.txt cargados en la lista de jugadores";
            break;
        case 2:
            ruleta_.escribeJugadores();
            cout<<"jugadores guerdados en el fichero jugadores.txt";
            break;
        case 3:
            ruleta_.getEstadoRuleta(nJugadores_, dineroMesa_ ,nLanzamientos_, ganaciaBanca_);
            cout<<"Numero de jugadores: "<< nJugadores_ <<endl;
            cout<<"Dinero de la mesa:  "<< dineroMesa_ <<endl;
            cout<<"Numero de lanzamientos: "<< nLanzamientos_ <<endl;
            cout<<"Ganancia de la banca: "<< ganaciaBanca_ <<endl;
            break;
        case 4:
            list<Jugador>jugadores_=ruleta_.getJugadores(); //compio la lista de jugadores porque no puedo usarla a l estar en la parte privada
            ruleta_.giraRuleta();
            cout<<"la bola es: "<<ruleta_.getBola()<<endl;
            ruleta_.getPremios();
            for(auto i = jugadores_.begin(); i != jugadores_.end(); i++){
                cout<<"el jugador cuyo dni es: "<<(i->getDNI())<<" , tiene: "<<(i->getDinero())<<" dinero."<<endl;
            }
            cout<<"Dinero de la banca: "<<ruleta_.getBanca()<<endl;
            break;
        
        
        
    }

    
}