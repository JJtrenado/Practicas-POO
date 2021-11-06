#include "ruleta.h"

bool Ruleta::setBanca(int const &banca){ //solo admite valores positivos. En caso contrario devuelve false.
    if(banca>=0){
        banca_=banca;
        return true;
    }
    return false;
}

bool Ruleta::setBola(int const &bola){  //solo admite valores entre 0 y 36. En caso contrario devuelve false.
    if(bola>=0 && bola<=36){
        bola_=bola;
        return true;
    }
    return false;
}

/*El método bool addJugador() recibe un jugador como parámetro y añade el
jugador al final de la lista de jugadores y crea un fichero tipo texto de
apuestas vacío y devuelvve true. El fichero debe llamarse DNI.txt, siendo DNI
el DNI del jugador. Si el fichero ya existe, lo deja como estaba sin
modificarlo ni borrarlo. Si ya existe en la lista un jugador con ese DNI el
método no hace nada y devuelve false.*/
bool Ruleta::addJugador(Jugador const &jugador){
    // primero compruebo si el jugador ya existe recorriendo la lista de jugadores
    for (std::list<Jugador>::iterator i = jugadores_.begin(); i != jugadores_.end(); i++){
        if(i->getDNI()==jugador.getDNI()){
            return false; //si ya existe deuelvo false
        }
    }
    jugadores_.push_back(jugador); // si no existe lo añado al final
    
    // ahora creo un fichero si el jugador no existia
    fstream file;
    string fileName = jugador.getDNI() + ".txt";
    file.open(fileName);
    file.close();

    return true;
}

// aqui creo que hay sobrecarga de funciones
        
/*El método int deleteJugador() recibe el DNI de un jugador y borra de la lista de
jugadores el jugador con ese DNI. Debe devolver 1 si se ha borrado al jugador,
-1 si la lista está vacía y -2 si el DNI no se ha encontrado en la lista de
jugadores. No debe borrar el fichero con las apuestas de ese jugador.*/
int Ruleta::deleteJugador(string const &dni){
    if(jugadores_.empty()) return -1;      // devuelvo -1 si está vacia

    // primero compruebo si el jugador ya existe recorriendo la lista de jugadores
    for (list<Jugador>::iterator i = jugadores_.begin() ; i!=jugadores_.end() ; i++){
        if(i->getDNI()==dni){
            jugadores_.erase(i); //si existe lo elimino
            return 1;
        }
    }
    return -2;
}
/*El método int deleteJugador() recibe un objeto de la clase Jugador y borra de
la lista de jugadores el jugador con mismo DNI que el recibido. Debe devolver
1 si se ha borrado al jugador, -1 si la lista está vacía y -2 si el DNI no se ha
encontrado en la lista de jugadores. No debe borrar el fichero con las
apuestas de ese jugador.*/
int Ruleta::deleteJugador(Jugador const &jugador){                              //Función que borra a un jugador de la lista pasando un objeto del tipo Jugador como parámetro
    if(jugadores_.empty()) return -1;                                           //Se devuelve -1 si la lista esta vacia

    for (auto i=jugadores_.begin(); i!=jugadores_.end(); i++){                  //Recorremos la lista para buscar si ya existe el jugador que queremos eliminar
        if(i->getDNI()==jugador.getDNI()){
            jugadores_.erase(i);                                                //Eliminamos el jugador
            return 1;
        }
    }
    return -2;                                                                  //Se devuelve -2 si no hemos encontrado al jugador que queremos borrar
}/*El método void escribeJugadores() escribe los datos de la lista de jugadores en
un fichero texto denominado jugadores.txt. Cada vez que se escribe este
fichero se borra todo su contenido anterior. El formato de este archivo
debe ser:
DNI,código,nombre,apellidos,dirección,localidad,provincia,país,dinero
DNI,código,nombre,apellidos,dirección,localidad,provincia,país,dinero
. . .
Si alguno de los campos está vacío el fichero quedaría de la forma:DNI,código,nombre,apellidos,,,,,dinero
DNI,código,,,,,,,dinero
. . .
(recordar que DNI y código de jugador es obligatorio en Jugador)*/
void Ruleta::escribeJugadores(){                                    //Funcion que escribe los datos de la lista de jugadores en un fichero
    std::fstream f;
    f.open("jugadores.txt", std::ios::out);
    for (auto i= jugadores_.begin(); i!=jugadores_.end(); i++){     //Cada vez que entremos en el bucle, estaremos en un jugador distinto, del cual se iran escribiendo sus datos en el fichero separados por comas
        f<<i->getDNI()<<","<<
        i->getCodigo()<<","<<
        i->getNombre()<<","<<
        i->getApellidos()<<","<<
        i->getDireccion()<<","<<
        i->getLocalidad()<<","<<
        i->getProvincia()<<","<<
        i->getPais()<<","<<
        i->getDinero()<<","<<std::endl;
    }
    f.close();
}/*El método void leeJugadores() lee los datos de los jugadores del fichero
jugadores.txt y los mete en la lista de jugadores. La lista de jugadores se
borra antes de añadir los jugadores del fichero jugadores.txt*/
void Ruleta::leeJugadores(){                                                                                    //Funcion que escribe los datos de un fichero en la lista jugadores
    jugadores_.empty();                                                                                         //Al comienzo, vaciamos la lista de jugadores
    std::fstream f;
    f.open("jugadores.txt", std::ios::in);
    
    char dni[255], codigo[255], nombre[255], apellidos[255]; 
    char direccion[255], localidad[255], provincia[255], pais[255], dinero[255];                                //Creamos variables para almacenar temporalmente los datos del jugador
    
    while(f.getline(dni, 255, ',')){
            
        f.getline(codigo, 255, ',');
        f.getline(nombre, 255, ',');
        f.getline(apellidos, 255, ',');
        f.getline(direccion, 255, ',');
        f.getline(localidad, 255, ',');
        f.getline(provincia, 255, ',');
        f.getline(pais, 255, ',');
        f.getline(dinero, 255, '\n');

        Jugador aux (dni, codigo, nombre, apellidos, 0, direccion, localidad, provincia, pais, atoi(dinero));   //Creamos un jugador aux y le pasamos sus datos
        jugadores_.push_back(aux);                                                                              //Pasamos aux a la lista
    }
    f.close();
}
/*El método void getPremios() recorre la lista de jugadores y carga sus apuestas
de los ficheros correspondientes. Actualiza el dinero de cada jugador con lo
que ha ganado o ha perdido en cada apuesta, y actualiza el dinero de la banca
con lo que ha ganado o ha perdido en cada apuesta.*/
void Ruleta::getPremios(){                                                              //Funcion que actualiza el dinero ganado o perdido por los jugadores
    for (auto i=jugadores_.begin(); i!=jugadores_.end(); i++){
        i->setApuestas();                                                               //Se hacen las apuestas
        std::list<Apuesta> aux = i->getApuestas();                                      //Se guardan las apuestas en una lista auxiliar
        for (auto j=aux.begin(); j!=aux.end(); j++){
            Apuesta apuesta= *j;
            switch(apuesta.tipo){                                                       //Segun el tipo de apuesta, entraremos en un caso del switch o en otro
                
                case 1:                                                                 //Apuesta sencilla
                    if (bola_ == stoi(apuesta.valor)){                                  //Si sale el numero de la bola que habia apostado el jugador, gana el jugador y pierde la banca
                        setBanca(getBanca() - 35*apuesta.cantidad);                     
                        i->setDinero(i->getDinero() + (apuesta.cantidad*35));           
                    }
                    else{                                                               //Si no sale el numero de la bola que habia apostado el jugador, gana la banca y pierde el jugador
                        setBanca(getBanca() + apuesta.cantidad);                        
                        i->setDinero(i->getDinero() - apuesta.cantidad);                             
                    }
                break;

                case 2:                                                                                                     //Apuesta rojo o negro
                    if (bola_==0){                                                                                          //Si la bola que sale es 0, gana la banca y pierde el jugador
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                    }

                    else if ((apuesta.valor=="rojo"&& esRoja(bola_)) || (apuesta.valor=="negro" && !esRoja(bola_))){        //Si el color de la bola coincide con el color apostado, gana el jugador y pierde la banca
                        setBanca(getBanca() - apuesta.cantidad);
                        i->setDinero(i->getDinero()+(apuesta.cantidad));
                    }

                    else{                                                                                                   //Si el color de la bola no coincide con el color apostado, gana la banca y pierde el jugador
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                    }

                break;

                case 3:                                                                                                     //Apuesta par o impar
                    if (bola_==0){                                                                                          //Si la bola que sale es 0, gana la banca y pierde el jugador
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                    }
                    else if ( (apuesta.valor=="par"&& esPar(bola_)) || (apuesta.valor=="impar" && !esPar(bola_))){          //Si la paridad de la bola coincide con la apostada, gana el jugador y pierde la banca
                        setBanca(getBanca() - apuesta.cantidad);
                        i->setDinero(i->getDinero()+(apuesta.cantidad));
                    }

                    
                    else{                                                                                                   //Si la paridad de la bola no coincide con la apostada, gana la banca y pierde el jugador
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);

                    }
                break;

                case 4:                                                                                                     //Apuesta alto o bajo                                                                 
                    if (bola_==0){                                                                                          //Si la bola que sale es 0, gana la banca y pierde el jugador
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                    }

                    else if ( (apuesta.valor=="alto"&& esAlta(bola_)) || (apuesta.valor=="bajo" && !esAlta(bola_))){        //Si la bola y la apuesta son ambas alta o ambas baja, gana el jugador y pierde la banca
                        setBanca(getBanca() - apuesta.cantidad);
                        i->setDinero(i->getDinero()+(apuesta.cantidad));
                    }

                    else{                                                                                                   //Si la bola y la apuesta son una alta y una baja (o viceveersa), gana la banca y pierde el jugador
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                        
                    }
                break;
            }
        }
    }
}

bool Ruleta::esRoja(int const &valor){      //Funcion que determina si la bola es roja o no
    int rojos[18] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
        for(int i=0; i<18; i++){
            if(valor == rojos[i]){
                return true;                //Si es roja devolvera true
            }
        }
    return false;                           //Si es negra devolvera false
}


bool Ruleta::esPar(int const &valor){       //Funcion que determina si la bola es par o no              
    if (valor%2==0){
        return true;                        //Si es par devolvera true
    }
    return false;                           //Si es impar devolvera false
}


bool Ruleta::esAlta(int const &valor){      //Funcion que determina si la bola es un valor alto o no
    if (valor>=1 && valor<=18){
        return false;                       //Si esta entre 1 y 18 devolvera false
    }
    return true;                            //Si esta entre 19 y 36 devolvera false
}


