#include <unistd.h>
#include <stdio.h>
#include <string.h>
//#include "stblib.h"

//cuidado c os waits deadlock
////////////////////////////////// EX 1 
int pai2filho (){
    int p[2];
    char line[7] ={"linha1"};
    char buffer[20];
    int res;

    if(pipe(p)== -1){
        printf("error");
        return -1;
    }

    switch(fork()){
    case 0:
    close(p[1]);
    res=read(p[0],&buffer,sizeof(buffer));
    printf("[FILHO]:read %s from pipe res %d\n",buffer,res);
    close(p[0]);
    _exit(0);

    default :
    close(p[0]);
    //sleep(5);
    write(p[1],&line,sizeof(strlen(line)));
    printf("[PAI]:wrote line ");
    close (p[1]);

}
return 0;
}
////////////////////////////////// EX2 
int pai2filhostring (){
    int p[2];
    char *line[30] ={"linha1\n,linha2\n,linha3\n"};
    char buffer;
    int num_lines =3;
    int res;

    if(pipe(p)== -1){
        printf("error");
        return -1;
    }

    switch(fork()){
    case 0:
    close(p[1]);

    while (read(p[0],&buffer,1)>0){ // readln era melhor 
    printf("[FILHO]:read %c from pipe\n",buffer);
   }
    close(p[0]);
    _exit(0);

    default :

    close(p[0]);
    //sleep(5);
    for( int i =0; i<num_lines;i++){ 
    write(p[1],line[i],sizeof(strlen(line[i])));
    printf("[PAI]:wrote line %s\n",line[i]);
    }
    close (p[1]);

    }
return 0;
}
//////////////////////////////// EX 3 --- usar execpl /exe..guiao3
int ex3 (){
    int p[2];
    char *buffer;
    //char espacos;
    int res;
    if(pipe(p)== -1){
        printf("error");
        return -1;
    }
    execvp("wc","wc");

    switch(fork()){
    case 0:
    close(p[1]);
    while (readln(p[0],buffer[s],1)>0){
        if (strcmp (buffer," ")==0){
            a++; ///substituido por execpl(...) and/or strdup
    }
    printf("[FILHO]:read %c from pipe\n",buffer);
    }
    default:
    close(p[0]);
    write(p[1],line[i],sizeof(strlen(line[i])));

}
}
///// EX 4 -> 1 pipe
int ex4 (){
    int p[2];
    char *buffer;
    int res;
    if(pipe(p)== -1){
        printf("error");
        return -1;
    }
}
////  EX 5 -> cria-se o pipe dps faz-se o fork no do meio !  no do fim so se faz fork /_\ ...MUITO IMPORTANTE _sofaltam os forks de resto engloba td

int main (){
    pai2filhostring();
    return 0;
}