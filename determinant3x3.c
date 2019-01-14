#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

//str int cevrim
int strint( char* charnums)
{
 int number=0;
 int index=0;
 while(charnums[index])
 {
    if(('0'<=charnums[index]) && (charnums[index]<='9'))
    {

        if(!number)
            number= ( (int) charnums[index]) - 48;
        else
        {
            number = (number *= 10) + ((int) charnums[index] - 48);
        }
        index++;
    }
    else
    {
        number=-1;
        printf("\nGecersiz islem");
        break;
    }
}
return number;
}


int main()
{


 int pipefd[2];
      //pipe olustur
 if (pipe(pipefd) < 0) {
    perror("pipe");
    exit(1);
}
char cevap;
int matrix[3][3];
do {
// kullanıcıya 3X3 matrix gösterimi:
printf("3X3 Matrisi Doldurunuz : \n");
int cnt=1;
for (int i=0;i<3 ; i++){
    printf("|  ");
    for(int j=0 ;j<3;j++){
        printf("%d  ",cnt++);
    }
    printf(" |\n\n");
}
//kullanıcı matris doldurması:
int x;
for (int i=0;i<3 ; i++){
    for(int j=0 ;j<3;j++){
       scanf(" %d", &x);
       matrix[i][j]=x;
    }
}

// 3X3 matrix yazdırma : 
for (int i=0;i<3 ; i++){
    printf("|  ");
    for(int j=0 ;j<3;j++){
        printf("%d  ",matrix[i][j]);
    }
    printf(" |\n\n");
}

    // _______________
   // int i=0;
    int fv,ex;
    char  randomss[10]; //SatSutSet ten gelen değer
    char *sat_sut;
    int sat_sut_no;
    fv= fork();
    if(fv==0){
        ex= execv("satsutsec", NULL);
                // hata olusursa
        perror("SatSutSec : execute failed");
    }else{
        wait(&ex); // waiting SatSutSec program to select a row/column randomly
        read(pipefd[0], randomss, sizeof(randomss));
        printf("Ana Program : Random secilen  : %s\n",randomss);
        sat_sut = strtok(randomss, " ");  // spilt 'satır 3' to satır and 3
        sat_sut_no =strint(strtok(NULL, " ")); // 3
       // printf("%s\n",sat_sut );
        //printf("%d\n",sat_sut_no );

    int a; // element of selected row/column in (a11*A2x2 + a12*A2x2 ..)    
    int A[4]; //  2x2 matrix to find its determinate
    int Ai=0; // iterable index for A
    int secilenElemenSS[2]; //secilen elemanın satrı ve sutunu :a11 -> 1,1
    int det=0;
    int kofakSonuc=0;

    for (int k=0;k<3;k++){

        if (strcmp(sat_sut,"satır")==0){

       //for (int k=0;k<3;k++){
            Ai=0; // A indexi sıfırlama
            a=matrix[sat_sut_no-1][k]; // kofaktor elemanı
            printf("a= %d\n",a );
            // A 2x2 matris olusruma
            for(int i=0 ; i<3;i++){
                for (int j =0 ; j<3 ; j++){
                    if(i!=sat_sut_no-1 && j!=k){ // aynı satırda ve sutunde olmayanları A2x2 matrisine ekle
                        A[Ai++]=  matrix[i][j]; // adding elements to A
                    }
                }
            }
            // A 2x2 matrix yazdırma :
            for (int i=0;i<4 ; i++){
                if (i==2)printf("\n");
                printf("%d  ",A[i]);
            }
            printf("\n");
        
            secilenElemenSS[0]=sat_sut_no;
            secilenElemenSS[1]=k+1;

            printf("________\n");
        //}        
        }else {
            // for (int k=0;k<3;k++){
            Ai=0; // A indexi sıfırlama
            a=matrix[k][sat_sut_no-1];
            printf("a= %d\n\n",a );

            // A 2x2 matris olusruma
            for(int i=0 ; i<3;i++){
                for (int j =0 ; j<3 ; j++){
                    if(i!=k && j!=sat_sut_no-1){ // aynı satırda ve sutunde olmayanları A2x2 matrisine ekle
                        A[Ai++]=  matrix[i][j]; // adding elements to A
                    }
                }
            }
            // A 2x2 matrix yazdırma :
            for (int i=0;i<4 ; i++){
                if (i==2)printf("\n");
                printf("%d  ",A[i]);
            }
            printf("\n");
            secilenElemenSS[0]=k+1;
            secilenElemenSS[1]=sat_sut_no;

            printf("________\n");
            //}
        }


        fv = fork();

        if(fv ==0){
            write(pipefd[1],&A , 4*sizeof(int)); //2x2 A gönder
            // kofaktor program çağrılması:
            ex= execv("kofakhesap2x2", NULL);
                        // hata olusursa
            perror("execute failed");
        }else {
                            //sleep(2);
           sleep(1);
           write(pipefd[1],&secilenElemenSS , 2*sizeof(int)); // secilen satır sutun gonder
           //printf("Ana prog waiting ..\n");
           wait(&ex); // kofaktor hesaplanmasını bekle
            
            read(pipefd[0], &kofakSonuc, sizeof(int));// kofaktor hesap sonucu pipten okuma
                    //close(pipefd[0]);
            printf("Ana prog: kofaktor Sonuç : %d \n",kofakSonuc );

        }
            printf("______________\n");
            det+=a*kofakSonuc; 
    }
        
        printf("Determinant = %d\n",det);
        printf("_____________________\n");
        

    }
    printf("Yeni işlem yapmak istiyor musunuz E/H ?\n");
    scanf(" %c",&cevap);
    while(cevap!='E' && cevap!= 'H'){
      printf("Yeni işlem yapmak istiyor musunuz E/H ? (evet/hayır)\n");
      scanf(" %c",&cevap);  
    }
}while(cevap!='H');
    return 0;
}
