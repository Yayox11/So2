#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include "game.h"

void game_logic(int* pipes, int n_pipes,int i, deck_t *mem, int* turno){
  int pipes_player[8],k,carta_elegida,juego_terminado = 0;
  card_t carta_leida;
  if(i==3){
    pipes_player[8]=(pipes[0],pipes[1],pipes[2],pipes[3],pipes[12],pipes[13],pipes[14],pipes[15]);
  }
  else{
    for(k = 0;k<8;k++){
      pipes_player[k]=*pipes + k + (8-(i*4));
    }
  }
  deck_t mano;
  mano.cantidad = 0;
  for(k = 0;k<7;k++){
    mano.cartas[k]=deck_siguiente(mem);
    mano.cantidad++;
  }
  mano.posicion = 0;
  if(*turno == 1 && i == 3){
    close(pipes_player[0]);
    close(pipes_player[5]);
    printf("El jugador %d ha sacado las siguientes cartas\n",i);
    mostrar_mano(&mano);
    printf("Seleccione el Indice a lanzar\n");
    scanf("%d",&carta_elegida);
    write(pipes_player[1],mano.cartas[carta_elegida-1],sizeof(mano.cartas[carta_elegida-1]));
    sleep(2);
    read(pipes_player[4],&carta_leida,sizeof(carta_leida));
    *turno++;
    printf("Turno %d\n",*turno);
  }
  else{
    printf("El jugador %d ha sacado las siguientes cartas\n",i);
    mostrar_mano(&mano);
    close(pipes_player[1]);
    read(pipes_player[0],&carta_leida,sizeof(carta_leida));
    printf("La Carta leida en el proceso %d es: ",i );
    mostrar_valores(&carta_leida);
  }
}
