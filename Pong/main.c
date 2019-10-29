#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define V 21
#define H 75

void iniciar(char campo[V][H], int pelX, int pelY, int iniJug, int finJug, int iniIA, int finIA);
void marcar_borde(char campo[V][H]);
void crear_raqueta(char campo[V][H], int iniJug, int finJug);
void crear_raqueta_IA(char campo[V][H], int iniIA, int finIA);
void crear_pelota(char campo[V][H], int pelX, int pelY);
void mostar_campo(char campo[V][H]);
void game_loop(char campo[V][H], int pelX, int pelY, int iniJug,    int finJug, int iniIA, int finIA, int modX, int modY, int modIA);
void draw(char campo[V][H]);
void input(char campo[V][H], int *pelX, int *pelY, int *iniJug, int *finJug, int *iniIA, int *finIA, int *modX, int *modY, int *modIA, int *gol);

int main(){

    int pelX, pelY, iniJug, finJug, iniIA, finIA; // Posicion
    int modX, modY, modIA; // Modificacion
    char campo[V][H];

    // Iniciar variables de Posicion
    pelX = 37;
    pelY = 10;
    iniJug = 8;
    finJug = 12;
    iniIA = 8;
    finIA = 12;

    // Iniciar variables de modificacion
    modX = -1;
    modY = -1;
    modIA = -1;


    iniciar(campo, pelX, pelY, iniJug, finJug, iniIA, finIA);
    game_loop(campo, pelX, pelY, iniJug, finJug, iniIA, finIA, modX, modY, modIA);

    return 0;
}

void iniciar(char campo[V][H], int pelX, int pelY, int iniJug,    int finJug, int iniIA, int finIA){
    marcar_borde(campo);
    crear_raqueta(campo, iniJug, finJug);
    crear_raqueta_IA(campo, iniIA, finIA);
    crear_pelota(campo, pelX, pelY);
}

void marcar_borde(char campo[V][H]){
    int i, j;

    for(i = 0; i < V; i++){
        for(j = 0; j < H; j++){
            if(i == 0 || i == V-1)
                campo[i][j] = '-';
            else if(j == 0 || j == H-1)
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
        //update(); // Actualizar la matriz

        Sleep(10);
    }while(gol == 0);
}

void draw(char campo[V][H]){
    system("cls");
    mostar_campo(campo);
}

void input(char campo[V][H], int *pelX, int *pelY, int *iniJug, int *finJug, int *iniIA, int *finIA, int *modX, int *modY, int *modIA, int *gol){
    int i;

    // Verificaciones
    if(*pelY == 1 || *pelY == V-2)
        *modY *= -1;

    if(*pelX == 1 || *pelX == H-2)
        *gol = 1;

    if(*pelX == 4)
        for(i = (*iniJug); i <= (*finJug); i++)
            if(i == (*pelY))
                *modX *= -1;

    if(*pelX == H-5)
        for(i = (*iniIA); i <= (*finIA); i++)
            if(i == (*pelY))
                *modX *= -1;

    // Modificaciones


}
