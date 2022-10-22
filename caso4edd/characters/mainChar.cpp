#include "Character.h"
#include <thread>
#include <ctime>
#include<cstdio>
#include "Strategy/DoubtfulStrategy.h"
#include "Strategy/Strategy.h"

using namespace std;

#define GAME_DURATION 120       // en segundos

#define MAX_CHARACTERS 3
#define EXPLORER_SPEED 20
#define EXPLORER_LOAD_CAPACITY 8
#define CARGUERO_SPEED 10
#define CARGUERO_LOAD_CAPACITY 40
#define TOPO_SPEED 7
#define TOPO_LOAD_CAPACITY 15

//struct timespec pausa = {10,0};     // solo para probar algo

int selectedCharacters[MAX_CHARACTERS];
int selectedStrategies[MAX_CHARACTERS];
Character *playerCharacters[MAX_CHARACTERS];
Strategy *strategyList [MAX_CHARACTERS];

List<Door> *pListaDoors;


enum characters{
    explorador = 1,
    carguero = 2,
    topo = 3
};
enum strategies{
    doubtfulStrategy = 1,
    carefulStrategy = 2,
    selflessStrategy = 3,
};

enum amountCharacters{
    personajeUno = 0,
    personajeDos = 1,
    personajeTres = 2
};

/*
void characterOneSimulation(List<Door> *pListaDoors){
    playerCharacters[personajeUno]->play(pListaDoors);

}
void characterTwoSimulation(List<Door> *pListaDoors){
    playerCharacters[personajeDos]->play(pListaDoors);

}
void characterThreeSimulation(List<Door> *pListaDoors){
    playerCharacters[personajeTres]->play(pListaDoors);
}
*/

void charactersSimulation(){
    cout << "inicia" << endl;
    playerCharacters[personajeUno]->play(pListaDoors);
    playerCharacters[personajeDos]->play(pListaDoors);
    playerCharacters[personajeTres]->play(pListaDoors);
}

void loadStrategies(){
    for (int index = 0; index < MAX_CHARACTERS; ++index){
        Strategy *strategy;
        if(selectedStrategies[index] = doubtfulStrategy){
            strategy = new DoubtfulStrategy();
            strategy->registerObserver(playerCharacters[index]);
            playerCharacters[index]->setCharacterStrategy(strategy);
        }
        else if(selectedStrategies[index] = carefulStrategy){
            //strategy = new CarefulStrategy();
            playerCharacters[index]->setCharacterStrategy(strategy);
        }
        else{
            //strategy = new SelflessStrategy();
            playerCharacters[index]->setCharacterStrategy(strategy);
        }
    }
}

void loadCharacters(){
    // se crean los personajes del jugador
    for(int index = 0; index < MAX_CHARACTERS; ++index){
        Character *character;
        if (selectedCharacters[index] == explorador){
            character = new Character("explorador", EXPLORER_LOAD_CAPACITY, EXPLORER_SPEED);
        }
        else if(selectedCharacters[index] == carguero){
            character = new Character("carguero", CARGUERO_LOAD_CAPACITY, CARGUERO_SPEED);
        }
        else{
            character = new Character("topo", TOPO_LOAD_CAPACITY, TOPO_SPEED);
        }
        playerCharacters[index] = character;
    }

}

void createDoor(){
    cout << "aqui" << endl;
    Door* puerta = new Door();
    
}

void askPlayer(){
    /* 
        cout << "\n-Seleccione sus personajes y estrategias-" << endl;
        cout << "\nPersonajes:                   | Estrategias" << endl;
        cout << "   Explorador (1)             |    Doubtful Strategy   (1)" << endl;
        cout << "   Carguero   (2)             |    Careful Strategy    (2)" << endl;
        cout << "   Topo       (3)             |    Selfless Strategy   (3)" << endl;

        cout << "\nPersonaje 1: ";
        cin >> selectedCharacters[0];
        cout << "\nEstrategia del personaje 1: ";
        cin >> selectedStrategies[0];
        cout << "Personaje 2: ";
        cin >> selectedCharacters[1];
        cout << "\nEstrategia del personaje 2: ";
        cin >> selectedStrategies[1];
        cout << "Personaje 3: ";
        cin >> selectedCharacters[2];
        cout << "\nEstrategia del personaje 3: ";
        cin >> selectedStrategies[2];
        */
       selectedCharacters[0] = 1;
       selectedStrategies[0] = 1;
       selectedCharacters[1] = 1;
       selectedStrategies[1] = 1;
       selectedCharacters[2] = 1;
       selectedStrategies[2] = 1;


        loadCharacters();
        loadStrategies();
 
}


// para probar que los personajes dejen de hacer lo que sea cuando acabe el tiempo
void gameSimulation(){
    time_t startTime = time(NULL);
    cout << "\nHora de inicio de la partida: " << ctime(&startTime) << endl;
    clock_t now = clock();      //para marcar la hora
    askPlayer();
    createDoor();
    thread charactersThread(charactersSimulation);
    charactersThread.join();
    //while(clock() - now < GAME_DURATION * CLOCKS_PER_SEC){
    //}

    time_t final = time(NULL);
    cout << "Hora de finalizacion de la partida: " << ctime(&final) << endl;
}

int main(){
    /*
    srand(time(0));
    RECORDAR: cuando utilizamos rand hay que inicializar srand una vez al inicio del programa
    para que rand no genere los mismos numeros todas las veces!!!!
    */
    
    thread gameThread(gameSimulation);
    gameThread.join();

    /*
    //solo para chequear que este funcionando
    for(int i = 0; i < MAX_CHARACTERS; ++i){
        cout << playerCharacters[i]->getName() << endl;
        
    }
    */

}


