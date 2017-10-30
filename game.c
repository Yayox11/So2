#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include "game.h"

void game_logic(int* pipes, int n_pipes,int i){
  if(i == 3){
    close(pipes[0]);
  }
}
