#include <iostream>
#include <string>
#include <sstream>
#include "Door.h"

using namespace std;


int main() {

    Door* puerta = new Door();
    puerta->generarConexiones(7);

    return 0;
}