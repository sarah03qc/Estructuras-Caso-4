#include "Character.h"

using namespace std;

#define MAX_CHARACTERS 3
#define EXPLORER_SPEED 20
#define EXPLORER_LOAD_CAPACITY 8
#define CARGUERO_SPEED 10
#define CARGUERO_LOAD_CAPACITY 40
#define TOPO_SPEED 7
#define TOPO_LOAD_CAPACITY 15


int selectedCharacters[MAX_CHARACTERS];
Character *playerCharacters[MAX_CHARACTERS];

enum characters{
    explorador = 1,
    carguero = 2,
    topo = 3
};

int main(){
    cout << "-Seleccione sus personajes-" << endl;
    cout << "\nPersonajes:" << endl;
    cout << "   Explorador (1) " << endl;
    cout << "   Carguero   (2)" << endl;
    cout << "   Topo       (3)" << endl;
    cout << "\nPersonaje 1: ";
    int character1;
    int character2;
    int character3;
    cin >> character1;
    selectedCharacters[0] = character1;
    cout << "Personaje 2: ";
    cin >> character2;
    selectedCharacters[1] = character2;
    cout << "Personaje 3: ";
    cin >> character3;
    selectedCharacters[2] = character3;
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
    /*
    solo para chequear que este funcionando
    for(int i = 0; i < MAX_CHARACTERS; ++i){
        cout << playerCharacters[i]->getName() << endl;
    }
    */

}