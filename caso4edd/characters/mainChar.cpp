#include "Character.h"

using namespace std;

int selectedCharacters[3];
Character playerCharacters[3];

enum characters{
    exporador = 1,
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

    for(int character: selectedCharacters){
        

    }

}