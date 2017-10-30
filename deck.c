#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include <math.h>

static int rand_int(int n) {
    int limit = RAND_MAX - RAND_MAX % n;
    int rnd;

    do {
        rnd = rand();
    }
    while (rnd >= limit);
    return rnd % n;
}

void shuffle(int *array, int n) {
    int i, j, tmp;

    for (i = n - 1; i > 0; i--) {
        j = rand_int(i + 1);
        tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
   }
}

static const card_t mazo_base[108] = {
             (TIPO_NUMERO,COLOR_AZUL,1),
             (TIPO_NUMERO,COLOR_AZUL,1),
             (TIPO_NUMERO,COLOR_ROJO,1),
             (TIPO_NUMERO,COLOR_ROJO,1),
             (TIPO_NUMERO,COLOR_AMARILLO,1),
             (TIPO_NUMERO,COLOR_AMARILLO,1),
             (TIPO_NUMERO,COLOR_VERDE,1),
             (TIPO_NUMERO,COLOR_VERDE,1),
             (TIPO_NUMERO,COLOR_AZUL,2),
             (TIPO_NUMERO,COLOR_AZUL,2),
             (TIPO_NUMERO,COLOR_ROJO,2),
             (TIPO_NUMERO,COLOR_ROJO,2),
             (TIPO_NUMERO,COLOR_AMARILLO,2),
             (TIPO_NUMERO,COLOR_AMARILLO,2),
             (TIPO_NUMERO,COLOR_VERDE,2),
             (TIPO_NUMERO,COLOR_VERDE,2),
             (TIPO_NUMERO,COLOR_AZUL,3),
             (TIPO_NUMERO,COLOR_AZUL,3),
             (TIPO_NUMERO,COLOR_ROJO,3),
             (TIPO_NUMERO,COLOR_ROJO,3),
             (TIPO_NUMERO,COLOR_AMARILLO,3),
             (TIPO_NUMERO,COLOR_AMARILLO,3),
             (TIPO_NUMERO,COLOR_VERDE,3),
             (TIPO_NUMERO,COLOR_VERDE,3),
             (TIPO_NUMERO,COLOR_AZUL,4),
             (TIPO_NUMERO,COLOR_AZUL,4),
             (TIPO_NUMERO,COLOR_ROJO,4),
             (TIPO_NUMERO,COLOR_ROJO,4),
             (TIPO_NUMERO,COLOR_AMARILLO,4),
             (TIPO_NUMERO,COLOR_AMARILLO,4),
             (TIPO_NUMERO,COLOR_VERDE,4),
             (TIPO_NUMERO,COLOR_VERDE,4),
             (TIPO_NUMERO,COLOR_AZUL,5),
             (TIPO_NUMERO,COLOR_AZUL,5),
             (TIPO_NUMERO,COLOR_ROJO,5),
             (TIPO_NUMERO,COLOR_ROJO,5),
             (TIPO_NUMERO,COLOR_AMARILLO,5),
             (TIPO_NUMERO,COLOR_AMARILLO,5),
             (TIPO_NUMERO,COLOR_VERDE,5),
             (TIPO_NUMERO,COLOR_VERDE,5),
             (TIPO_NUMERO,COLOR_AZUL,6),
             (TIPO_NUMERO,COLOR_AZUL,6),
             (TIPO_NUMERO,COLOR_ROJO,6),
             (TIPO_NUMERO,COLOR_ROJO,6),
             (TIPO_NUMERO,COLOR_AMARILLO,6),
             (TIPO_NUMERO,COLOR_AMARILLO,6),
             (TIPO_NUMERO,COLOR_VERDE,6),
             (TIPO_NUMERO,COLOR_VERDE,6),
             (TIPO_NUMERO,COLOR_AZUL,7),
             (TIPO_NUMERO,COLOR_AZUL,7),
             (TIPO_NUMERO,COLOR_ROJO,7),
             (TIPO_NUMERO,COLOR_ROJO,7),
             (TIPO_NUMERO,COLOR_AMARILLO,7),
             (TIPO_NUMERO,COLOR_AMARILLO,7),
             (TIPO_NUMERO,COLOR_VERDE,7),
             (TIPO_NUMERO,COLOR_VERDE,7),
             (TIPO_NUMERO,COLOR_AZUL,8),
             (TIPO_NUMERO,COLOR_AZUL,8),
             (TIPO_NUMERO,COLOR_ROJO,8),
             (TIPO_NUMERO,COLOR_ROJO,8),
             (TIPO_NUMERO,COLOR_AMARILLO,8),
             (TIPO_NUMERO,COLOR_AMARILLO,8),
             (TIPO_NUMERO,COLOR_VERDE,8),
             (TIPO_NUMERO,COLOR_VERDE,8),
             (TIPO_NUMERO,COLOR_AZUL,9),
             (TIPO_NUMERO,COLOR_AZUL,9),
             (TIPO_NUMERO,COLOR_ROJO,9),
             (TIPO_NUMERO,COLOR_ROJO,9),
             (TIPO_NUMERO,COLOR_AMARILLO,9),
             (TIPO_NUMERO,COLOR_AMARILLO,9),
             (TIPO_NUMERO,COLOR_VERDE,9),
             (TIPO_NUMERO,COLOR_VERDE,9),
             (TIPO_NUMERO,COLOR_AZUL,0),
             (TIPO_NUMERO,COLOR_ROJO,0),
             (TIPO_NUMERO,COLOR_AMARILLO,0),
             (TIPO_NUMERO,COLOR_VERDE,0),
             (TIPO_PLUS2,COLOR_AZUL,-1),
             (TIPO_PLUS2,COLOR_AZUL,-1),
             (TIPO_PLUS2,COLOR_ROJO,-1),
             (TIPO_PLUS2,COLOR_ROJO,-1),
             (TIPO_PLUS2,COLOR_AMARILLO,-1),
             (TIPO_PLUS2,COLOR_AMARILLO,-1),
             (TIPO_PLUS2,COLOR_VERDE,-1),
             (TIPO_PLUS2,COLOR_VERDE,-1),
             (TIPO_REVERTIR,COLOR_AZUL,-1),
             (TIPO_REVERTIR,COLOR_AZUL,-1),
             (TIPO_REVERTIR,COLOR_ROJO,-1),
             (TIPO_REVERTIR,COLOR_ROJO,-1),
             (TIPO_REVERTIR,COLOR_AMARILLO,-1),
             (TIPO_REVERTIR,COLOR_AMARILLO,-1),
             (TIPO_REVERTIR,COLOR_VERDE,-1),
             (TIPO_REVERTIR,COLOR_VERDE,-1),
             (TIPO_SALTO,COLOR_AZUL,-1),
             (TIPO_SALTO,COLOR_AZUL,-1),
             (TIPO_SALTO,COLOR_ROJO,-1),
             (TIPO_SALTO,COLOR_ROJO,-1),
             (TIPO_SALTO,COLOR_AMARILLO,-1),
             (TIPO_SALTO,COLOR_AMARILLO,-1),
             (TIPO_SALTO,COLOR_VERDE,-1),
             (TIPO_SALTO,COLOR_VERDE,-1),
             (TIPO_CAMBIO,COLOR_NEGRO,-1),
             (TIPO_CAMBIO,COLOR_NEGRO,-1),
             (TIPO_CAMBIO,COLOR_NEGRO,-1),
             (TIPO_CAMBIO,COLOR_NEGRO,-1),
             (TIPO_PLUS4,COLOR_NEGRO,-1),
             (TIPO_PLUS4,COLOR_NEGRO,-1),
             (TIPO_PLUS4,COLOR_NEGRO,-1),
             (TIPO_PLUS4,COLOR_NEGRO,-1)
           };

card_t* deck_siguiente(deck_t* d){
  if(d->posicion == DECK_EMPTY){
    perror("Mazo Vacio\n");
    exit(EXIT_FAILURE);
  }
  return d->cartas[d->posicion--];
}

void deck_iniciar(deck_t* d){
  int shuffle_index[108],i;
  for(i=0;i<108;i++){
    shuffle_index[i] = i;
  }
  shuffle(shuffle_index,108);
  for(i=0;i<108;i++){
    d->cartas[i]=*mazo_base[shuffle_index[i]];
  }

}

card_t* deck_mostrar(deck_t* d){
  if(d->posicion == DECK_EMPTY){
    perror("Mazo Vacio\n");
    exit(EXIT_FAILURE);
  }
  return d->cartas[d->posicion];
}

void deck_meter(deck_t* d, card_t* c){
  if(d == NULL){
    perror("Mazo NULO");
    exit(EXIT_FAILURE);
  }
  if(c == NULL){
    perror("Carta Nula");
    return;
  }
  if(d->posicion == DECK_SIZE - 1){
    perror("Mazo Vacio\n");
    exit(EXIT_FAILURE);
  }
  d->cartas[++d->posicion] = c;
}
