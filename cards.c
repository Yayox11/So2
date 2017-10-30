#include <stdio.h>
#include <stdlib.h>
#include "cards.h"



char* mostrar_carta_color(card_t* c){
  if(c == NULL){
    perror("Carta Nula\n");
    exit(EXIT_FAILURE);
  }
  switch(c->color){
    case COLOR_ROJO:
      return "Rojo";
    case COLOR_VERDE:
      return "Verde";
    case COLOR_AMARILLO:
      return "Amarilo";
    case COLOR_AZUL:
      return "Azul";
    case COLOR_NEGRO:
      return "Negro";
  }
}

char* mostrar_carta_tipo(card_t* c){
  if(c == NULL){
    perror("Carta Nula\n");
    exit(EXIT_FAILURE);
  }
  switch(c->tipo){
    case TIPO_PLUS2:
      return "Mas 2";
    case TIPO_PLUS4:
      return "Mas 4";
    case TIPO_SALTO:
      return "Salto de Jugador";
    case TIPO_REVERTIR:
      return "Cambio de Sentido";
    case TIPO_NUMERO:
      return "Numero";
  }
}

int mostrar_carta_numero(card_t *c){
  if(c == NULL){
    perror("Carta Nula\n");
    exit(EXIT_FAILURE);
  }
  return c->valor;
}

void mostrar_valores(card_t* c){
  if(c == NULL){
    perror("Carta Nula\n");
    exit(EXIT_FAILURE);
  }
  printf("Tipo: %s\nColor: %s\nNumero: %d",mostrar_carta_tipo(c), mostrar_carta_color(c),mostrar_carta_numero(c));
}
