#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "game.h"

void iniciar(char campo[V][H], int pelX, int pelY, int iniJug, int finJug, int iniIA, int finIA){
    marcar_borde(campo);
    crear_raqueta(campo, iniJug, finJug);
    crear_raqueta_IA(campo, iniIA, finIA);
    crear_pelota(campo, pelX, pelY);
}

void marcar_borde(char campo[V][H]){
    int i, j;

    for(i = 0; i < V; i++){
        for(j = 0; j < H; j++){
            if(i == 0 || i == V - 1)
                campo[i][j] = '-';
            else if(j == 0 || j == H - 1)
                campo[i][j] = '|';
            else
                campo[i][j] = ' ';
        }
    }

}

void crear_raqueta_IA(char campo[V][H], int iniIA, int finIA){
    int i, j;

     for(i = iniIA; i < finIA; i++){
        for(j = H-4; j < H-2; j++){
            campo[i][j] = 'X';
        }
    }
}

void crear_raqueta(char campo[V][H], int iniJug, int finJug){
    int i, j;

     for(i = iniJug; i < finJug; i++){
        for(j = 2; j < 4; j++){
            campo[i][j] = 'X';
        }
    }
}

void crear_pelota(char campo[V][H], int pelX, int pelY){
    campo[pelY][pelX] = 'O';
}

void mostar_campo(char campo[V][H]){
    int i, j;

    for(i = 0; i < V; i++){
        for(j = 0; j < H; j++){
            printf("%c", campo[i][j]);
        }
        printf("\n");
    }
}

void game_loop(char campo[V][H], int pelX, int pelY, int iniJug, int finJug, int iniIA, int finIA, int modX, int modY, int modIA){
    int gol = 0;

    do{
        draw(campo); // Dibujar en pantalla
        input(campo, &pelX, &pelY, &iniJug, &finJug, &iniIA, &finIA, &modX, &modY, &modIA, &gol); // Verificar y modificar
        iniciar(campo, pelX, pelY, iniJug, finJug, iniIA, finIA); // Actualizar la matriz
        Sleep(10);
    }while(gol == 0);
}

void draw(char campo[V][H]){
    system("cls");
    mostar_campo(campo);
}

void input(char campo[V][H], int *pelX, int *pelY, int *iniJug, int *finJug, int *iniIA, int *finIA, int *modX, int *modY, int *modIA, int *gol){
    int i;
    char key;

    // Verificaciones
    if(*pelY == 1 || *pelY == V - 2)
        *modY *= -1;

    if(*pelX == 1 || *pelX == H - 2)
        *gol = 1;

    if(*pelX == 4)
        for(i = (*iniJug); i <= (*finJug); i++)
            if(i == (*pelY))
                *modX *= -1;

    if(*pelX == H-5)
        for(i = (*iniIA); i <= (*finIA); i++)
            if(i == (*pelY))
                *modX *= -1;

    if(*iniIA == 1 || *finIA == V - 1)
        *modIA *= -1;

    // Modificaciones

    if(*gol == 0){
        // Pelota
        *pelX += (*modX);
        *pelY += (*modY);

        // Raqueta
        *iniIA += (*modIA);
        *finIA += (*modIA);
    }

    // Raqueta jugador
    if(kbhit() == 1){
        key = getch();

        if(key == 'w'){
            if(*iniJug != 1){
                *iniJug -= 1;
                *finJug -= 1;
            }
        }

        if(key == 's'){
            if(*finJug != V-1){
                *iniJug += 1;
                *finJug += 1;
            }
        }
    }
}


