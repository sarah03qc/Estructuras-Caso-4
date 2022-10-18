#include "Character.h"
#include <thread>
#include <ctime>
#include<cstdio>
#include "IStrategy.h"

using namespace std;

#define GAME_DURATION 120       // en segundos

#define MAX_CHARACTERS 3
#define EXPLORER_SPEED 20
#define EXPLORER_LOAD_CAPACITY 8
#define CARGUERO_SPEED 10
#define CARGUERO_LOAD_CAPACITY 40
#define TOPO_SPEED 7
#define TOPO_LOAD_CAPACITY 15

struct timespec pausa = {10,0};     // solo para probar algo

int selectedCharacters[MAX_CHARACTERS];
int selectedStrategies[MAX_CHARACTERS];
Character *playerCharacters[MAX_CHARACTERS];
IStrategy *strategyList [MAX_CHARACTERS];


enum characters{
    explorador = 1,
    carguero = 2,
    topo = 3
};
enum strategies{
    doubtfulStrategy = 0,
    egocentricStrategy = 1,
    evenStrategy = 2,
    oddStrategy = 3
};

void characterOneSimulation(){
    // playerCharacters[0]->empezar estrategia
    playerCharacters[0]->showCurrentState();

}
void characterTwoSimulation(){
    // playerCharacters[1]->empezar estrategia
    playerCharacters[1]->showCurrentState();

}
void characterThreeSimulation(){
    // playerCharacters[2]->empezar estrategia
    playerCharacters[2]->showCurrentState();
}

void loadCharactersAndStrategies(){
    // se crean los personajes del jugador
    for(int index = 0; index < MAX_CHARACTERS; ++index){
        Character *character;
        if (selectedCharacters[index] == explorador){
            character = new Character("explorador", EXPLORER_LOAD_CAPACITY, EXPLORER_SPEED);
            //character->setCharacterStrategy()
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

void askPlayer(){
        cout << "\n-Seleccione sus personajes y estrategias-" << endl;
        cout << "\nPersonajes:                   | Estrategias" << endl;
        cout << "   Explorador (1)             |    Doubtful Strategy   (1)" << endl;
        cout << "   Carguero   (2)             |    Egocentric Strategy (2)" << endl;
        cout << "   Topo       (3)             |    Even Strategy       (3)" << endl;
        cout << "                              |    Odd Strategy        (4)" << endl;

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
        loadCharactersAndStrategies();
 
}


// para probar que los personajes dejen de hacer lo que sea cuando acabe el tiempo
void gameSimulation(){
    time_t startTime = time(NULL);
    cout << "\nHora de inicio de la partida: " << ctime(&startTime) << endl;
    clock_t now = clock();      //para marcar la hora
    askPlayer();
    while(clock() - now < GAME_DURATION * CLOCKS_PER_SEC){
        thread charOneThread(characterOneSimulation);
        thread charTwoThread(characterTwoSimulation);
        thread charThreeThread(characterThreeSimulation);
        charOneThread.join();
        charTwoThread.join();
        charThreeThread.join();
        pthread_delay_np(&pausa);
    }
    time_t final = time(NULL);
    cout << "Hora de finalizacion de la partida: " << ctime(&final) << endl;
}

int main(){
    thread gameThread(gameSimulation);
    gameThread.join();

    /*
    //solo para chequear que este funcionando
    for(int i = 0; i < MAX_CHARACTERS; ++i){
        cout << playerCharacters[i]->getName() << endl;
        
    }
    */

}


