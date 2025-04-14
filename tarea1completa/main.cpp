#include <iostream>
#include <vector>
#include <string>
#include "ClasesS.h"
using namespace std;

//Definimos el main, asignando un espacio de memoria para el menu
//para poder establecer un puntero que llame al metodo mostrarMenu e inicialice el programa
int main() {
    Menu* menu = new Menu();
    menu->mostrarMenu();
    delete menu;
    return 0;
}