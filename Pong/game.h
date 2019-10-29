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

