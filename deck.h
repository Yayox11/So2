#include "cards.c"
#define DECK_SIZE 108
#define DECK_EMPTY -1

typedef struct deck_s{
  card_t* cartas[DECK_SIZE];
  card_t* cartas_botadas[DECK_SIZE];
  int posicion;
  int sentido;
  int cantidad;
}deck_t;

card_t* deck_siguiente(deck_t* d);

void deck_iniciar(deck_t* d);

card_t* deck_mostrar(deck_t* d);

void deck_meter(deck_t* d, card_t* c);

void mostrar_mano(deck_t*d);
