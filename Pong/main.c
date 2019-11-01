#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "game.h"

int main(){

    int pelX, pelY, iniJug, finJug, iniIA, finIA; // Posicion
    int modX, modY, modIA; // Modificacion
    char campo[V][H];

    // Iniciar variables de Posicion
    pelX = 37;
    pelY = 10;
    iniJug = 8;
    finJug = 12;
    iniIA = 5;
    finIA = 18;

    // Iniciar variables de modificacion
    modX = -1;
    modY = -1;
    modIA = -1;


    iniciar(campo, pelX, pelY, iniJug, finJug, iniIA, finIA);
    game_loop(campo, pelX, pelY, iniJug, finJug, iniIA, finIA, modX, modY, modIA);

    system("pause");
    return 0;
}
