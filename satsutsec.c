#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include  <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
   
  srand(time(NULL));   // Initialization, should only be called once.
  char * SatirSutun[6] ={"satır 1","satır 2","satır 3","sutun 1","sutun 2","sutun 3"};
  int r = rand()%6; // creating random between 0 and 5 
  //printf("SatSutSec : Random r = %d \n",r); //
  write(4 ,SatirSutun[r] , sizeof(SatirSutun[r])); // rastgele secileni pipe yaz

    return 0;
}
