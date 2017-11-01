#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include "game.c"


void* create_shared_memory(size_t size) {
  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_ANONYMOUS | MAP_SHARED;
  return mmap(NULL, size, protection, visibility, 0, 0);
}

int main(){
  int pipes[16];
  int n_players = 4, i, turno = 1;
  deck_t mazo;
  deck_iniciar(&mazo);
  deck_t* shmem = create_shared_memory(sizeof(mazo));
  memcpy(shmem,&mazo,sizeof(mazo));

  for(i=0;i<16;i+=2){
    pipe(pipes + i);
  }
  i = 0;
  while(i < n_players - 1){
    int pid = fork();
    if(pid == 0){
      close(pipes[5]);
      close(pipes[8]);
      close(pipes[12]);
      game_logic(pipes,16,i,shmem,&turno);
      exit(0);
    }
    ++i;
  }
  close(pipes[0]);
  close(pipes[3]);
  game_logic(pipes,16,3,shmem,&turno);
  pid_t pid2;
  int status;
  while ((pid2=wait(&status)) > 0);
  return 0;
}
