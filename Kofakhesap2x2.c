#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include  <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
  
    int A[2][2];
    int y1[4];
    int ss[2]; // secilen satır,sutun

    read(3, &y1, 4*sizeof(int)); //2x2 matrisi pipten oku, y1 e yaz
    sleep(1);
    read(3, &ss, 2*sizeof(int));
    printf("s satır  %d\n", ss[0]);
    printf("s sutun  %d\n", ss[1]);

    int p=ss[0]+ss[1];
    int det=y1[0]*y1[3]-(y1[1]*y1[2]);

    int sonuc= (int) pow(-1,(double)p);
    sonuc=sonuc*det;

    //printf("write sonuc to pipe: %d\n", sonuc);
        //sonucu pipe yaz
    write(4, &sonuc, sizeof(int));
        //close(pipefd[1]);
    return 0;
}
