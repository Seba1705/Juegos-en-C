    #include <stdio.h>
#include <stdlib.h>

void loop(char c[3][3]);
void iniciar_tablero(char c[3][3]);
void mostrar_tablero(char c[3][3]);
void poner_ficha(char c[3][3]);
void intro_IA(char c[3][3]);
int ganador(char c[3][3]);

int main(){
    char tablero[3][3];

    loop(tablero);

    return 0;
}

void loop(char c[3][3]){
    int i = 0, j;

    iniciar_tablero(c);

    do{
        system("clear");
        mostrar_tablero(c);

        (i % 2 == 0) ? poner_ficha(c) : intro_IA(c);

        mostrar_tablero(c);

        j = ganador(c);
        i++;

    }while(i <= 9 && j == 2);

    system("clear");
        mostrar_tablero(c);

    if(j == 0)
        printf("Has ganado!! \n\n");
    else if(j == 1)
        printf("Mala suerte! Perdiste!! \n\n");
    else if(j == 2)
        printf("Hubo un empate! \n\n");

}

void iniciar_tablero(char c[3][3]){
    int i, j;
    char auxiliar = '1';

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            c[i][j] = auxiliar++;
        }
    }

}

void mostrar_tablero(char c[3][3]){
    int i, j;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            (j < 2) ? printf(" %c |", c[i][j]) : printf(" %c ", c[i][j]);
        }
        printf("\n-----------\n");
    }
    printf("\n\n");
}

void poner_ficha(char c[3][3]){
    int i, j, k;
    char auxiliar;

    do{
        do{
            printf("Coloca una ficha: ");
            fflush(stdin);
            scanf("%c", &auxiliar);
        }while(auxiliar < '1' || auxiliar > '9');

        k = 0;

        switch(auxiliar){
            case '1':
                i = 0; j = 0;
                if(c[i][j] == 'X' || c[i][j] == 'O'){
                    k = 1;
                    printf("La casilla esta ocupada\n\n");
                }
                break;
            case '2':
                i = 0; j = 1;
                if(c[i][j] == 'X' || c[i][j] == 'O'){
                    k = 1;
                    printf("La casilla esta ocupada\n\n");
                }
                break;
            case '3':
                i = 0; j = 2;
                if(c[i][j] == 'X' || c[i][j] == 'O'){
                    k = 1;
                    printf("La casilla esta ocupada\n\n");
                }
                break;
            case '4':
                i = 1; j = 0;
                if(c[i][j] == 'X' || c[i][j] == 'O'){
                    k = 1;
                    printf("La casilla esta ocupada\n\n");
                }
                break;
            case '5':
                i = 1; j = 1;
                if(c[i][j] == 'X' || c[i][j] == 'O'){
                    k = 1;
                    printf("La casilla esta ocupada\n\n");
                }
                break;
            case '6':
                i = 1; j = 2;
                if(c[i][j] == 'X' || c[i][j] == 'O'){
                    k = 1;
                    printf("La casilla esta ocupada\n\n");
                }
                break;
            case '7':
                i = 2; j = 0;
                if(c[i][j] == 'X' || c[i][j] == 'O'){
                    k = 1;
                    printf("La casilla esta ocupada\n\n");
                }
                break;
            case '8':
                i = 2; j = 1;
                if(c[i][j] == 'X' || c[i][j] == 'O'){
                    k = 1;
                    printf("La casilla esta ocupada\n\n");
                }
                break;
            case '9':
                i = 2; j = 2;
                if(c[i][j] == 'X' || c[i][j] == 'O'){
                    k = 1;
                    printf("La casilla esta ocupada\n\n");
                }
                break;
        }
    }while(k == 1);

    c[i][j] = 'X';
}

void intro_IA(char c[3][3]){
    int i, j, k;
    char auxiliar;

    srand(time(NULL));

    do{
        i = rand() % 3;
        j = rand() % 3;
        k = 0;
        if(c[i][j] == 'X' || c[i][j] == 'O')
            k = 1;
    }while(k == 1);

    c[i][j] = 'O';
}

int ganador(char c[3][3]){
    if(c[0][0] == 'X' || c[0][0] == 'O'){
        if(c[0][0] == c[0][1] && c[0][0] == c[0][2])
            return (c[0][0] = 'X') ? 0 : 1; // Devuelve 0 si ganamos

        if(c[0][0] == c[1][0] && c[0][0] == c[2][0])
            return (c[0][0] = 'X') ? 0 : 1;

    }

    if(c[1][1] == 'X' || c[1][1] == 'O'){
        if(c[1][1] == c[0][0] && c[1][1] == c[2][2])
            return (c[1][1] = 'X') ? 0 : 1;

        if(c[1][1] == c[1][0] && c[1][1] == c[1][2])
            return (c[1][1] = 'X') ? 0 : 1;

        if(c[1][1] == c[2][0] && c[1][1] == c[0][2])
            return (c[1][1] = 'X') ? 0 : 1;

        if(c[1][1] == c[2][0] && c[0][1] == c[2][1])
            return (c[1][1] = 'X') ? 0 : 1;
    }

    if(c[2][2] == 'X' || c[2][2] == 'O'){
        if(c[2][2] == c[2][0] && c[2][2] == c[2][1])
            return (c[2][2] = 'X') ? 0 : 1;

        if(c[2][2] == c[0][2] && c[2][2] == c[1][2])
            return (c[2][2] = 'X') ? 0 : 1;
    }

    return 2;
}
