#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define V 21
#define H 65
#define N 100

typedef struct{
    int x, y, modX, modY;
    char imagen;
}snk;

typedef struct{
    int x, y;
}frt;

void inicio(int *tam, char campo[V][H]);
void marcar_borde(char campo[V][H]);
void ingresar_datos(char campo[V][H], int tam);

snk snake[N];
frt fruta;

int main() {
    int tam;
    char campo[V][H];

    inicio(&tam, campo);

    system("pause");
    return 0;
}

void inicio(int *tam, char campo[V][H]){
    int i;

    // Posicion cabeza serpiente
    snake[0].x = 32;
    snake[0].y = 10;

    // Tamanaño serpiente
    *tam = 4;

    // Coordenadas fruta
    srand(time(NULL));
    fruta.x = rand() % (H - 1);
    fruta.y = rand() % (V - 1);

    while(fruta.x == 0)
        fruta.x = rand() % (H - 1);

    while(fruta.y == 0)
        fruta.y = rand() % (H - 1);

    for(i = 0; i < *tam; i++){
        snake[i].modX = 1;
        snake[i].modY = 0;
    }

    marcar_borde(campo);
    ingresar_datos(campo, *tam);
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

void ingresar_datos(char campo[V][H], int tam){
    int i;

    for(i = 1; i < tam; i++){
        snake[i].x = snake[i - 1].x - 1;
        snake[i].y = snake[i - 1].y;
        snake[i].imagen = 'X';
    }

    snake[0].imagen = 'O';

    for(i = 0; i < tam; i++){
        campo[snake[i].y][snake[i].x] = snake[i].imagen;
    }

    campo[fruta.y][fruta.x] = '%';
}

//void
