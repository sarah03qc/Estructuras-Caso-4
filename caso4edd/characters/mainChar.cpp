#include "Character.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <ctime>
#include <cstdio>
#include "Strategy/DoubtfulStrategy.h"
#include "Strategy/CarefulStrategy.h"
#include "Strategy/SelflessStrategy.h"
#include "Strategy/Strategy.h"
#include "../gamemap/GameMap.h"

using namespace std;

#define GAME_DURATION 120       // en segundos

#define MAX_CHARACTERS 3
#define EXPLORER_SPEED 20
#define EXPLORER_LOAD_CAPACITY 8
#define CARGUERO_SPEED 10
#define CARGUERO_LOAD_CAPACITY 40
#define TOPO_SPEED 7
#define TOPO_LOAD_CAPACITY 15

struct timespec pausa = {10,0};     

int selectedCharacters[MAX_CHARACTERS];
int selectedStrategies[MAX_CHARACTERS];
Character *playerCharacters[MAX_CHARACTERS];
Strategy *strategyList [MAX_CHARACTERS];

List<Door> *pListaDoors;
Door* puertaRaiz;


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


void characterOneSimulation(){
    playerCharacters[personajeUno]->play(pListaDoors);
}
void characterTwoSimulation(){
    playerCharacters[personajeDos]->play(pListaDoors);
}
void characterThreeSimulation(){
    playerCharacters[personajeTres]->play(pListaDoors);
}

void loadStrategies(){
    for (int index = 0; index < MAX_CHARACTERS; ++index){
        Strategy *strategy;
        if(selectedStrategies[index] == doubtfulStrategy){
            strategy = new DoubtfulStrategy();
            playerCharacters[index]->setCharacterStrategy(strategy);
        }
        else if(selectedStrategies[index] == carefulStrategy){
            strategy = new CarefulStrategy();
            playerCharacters[index]->setCharacterStrategy(strategy);
        }
        else{
            strategy = new SelflessStrategy();
            playerCharacters[index]->setCharacterStrategy(strategy);
        }
        strategy->registerObserver(playerCharacters[index]);
    }
}

string checkAndAssingNames(int index, string characterName, int charType){
    int listaApariciones [MAX_CHARACTERS];
    int apariciones = 1;
    for(int counter = 0; counter < index; ++ counter){
        if(selectedCharacters[counter] == charType){
            ++ apariciones;
        }
    }
    characterName += to_string(apariciones);
    return characterName;
}

void loadCharacters(){
    // se crean los personajes del jugador
    for(int index = 0; index < MAX_CHARACTERS; ++index){
        Character *character;
        string name;
        if (selectedCharacters[index] == explorador){
            name = checkAndAssingNames(index, "explorador ", explorador);
            character = new Character(name, EXPLORER_LOAD_CAPACITY, EXPLORER_SPEED);
        }
        else if(selectedCharacters[index] == carguero){
            name = checkAndAssingNames(index, "carguero ", carguero);
            character = new Character(name, CARGUERO_LOAD_CAPACITY, CARGUERO_SPEED);
        }
        else{
            name = checkAndAssingNames(index, "topo ", topo);
            character = new Character(name, TOPO_LOAD_CAPACITY, TOPO_SPEED);
        }
        playerCharacters[index] = character;
    }

}

void askPlayer(){
        cout << "\n-Seleccione sus personajes y estrategias-" << endl;
        cout << "\nPersonajes:                   | Estrategias" << endl;
        cout << "   Explorador (1)             |    Doubtful Strategy   (1)" << endl;
        cout << "   Carguero   (2)             |    Careful Strategy    (2)" << endl;
        cout << "   Topo       (3)             |    Selfless Strategy   (3)" << endl;

        cout << "\nPersonaje 1: ";
        cin >> selectedCharacters[0];
        cout << "Estrategia del personaje 1: ";
        cin >> selectedStrategies[0];
        cout << "\nPersonaje 2: ";
        cin >> selectedCharacters[1];
        cout << "Estrategia del personaje 2: ";
        cin >> selectedStrategies[1];
        cout << "\nPersonaje 3: ";
        cin >> selectedCharacters[2];
        cout << "Estrategia del personaje 3: ";
        cin >> selectedStrategies[2];
        loadCharacters();
        loadStrategies();
}


// para probar que los personajes dejen de hacer lo que sea cuando acabe el tiempo
void gameSimulation(){
    time_t startTime = time(NULL);
    cout << "\nHora de inicio de la partida: " << ctime(&startTime) << endl;
    clock_t now = clock();      //para marcar la hora
    GameMap* juegomapa = new GameMap(10);
    puertaRaiz = juegomapa->getPuerta();
    pListaDoors = puertaRaiz->getConnectedDoors();
    askPlayer();
    thread charOneThread(characterOneSimulation);
    thread charTwoThread(characterTwoSimulation);
    thread charThreeThread(characterThreeSimulation);
    charOneThread.join();
    charTwoThread.join();
    charThreeThread.join();
    double duration = (clock() - now) / (double)CLOCKS_PER_SEC;
    cout << "DURACION " << duration << endl;
    while(duration < GAME_DURATION){
        duration = (clock() - now) / (double)CLOCKS_PER_SEC;
        cout << "DURACION " << duration << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    time_t final = time(NULL);
    cout << "CANTIDAD DE MINERALES: " << puertaRaiz->getMinerals() << endl;
    cout << "Hora de finalizacion de la partida: " << ctime(&final) << endl;

}

int main(){
    srand((unsigned) time(NULL));
    thread gameThread(gameSimulation);
    gameThread.join();
}


