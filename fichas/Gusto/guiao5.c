#include <unistd.h>
int pai2filho (){

int p[2];
char line[] = "Input para o consumidor";
int res, status;
char buffer[1024];
    //criar pipe
    if (pipe == -1) {
        perror("pipe not created.");
        return -1;
    }

    //criar processo
    switch (fork())
    {
    case -1:
        perror("Fork not made");
        return -1;
    case 0:
        //codigo filho
        // fechar descritor de escrita do filho
        close (p[1]);
        
        // usar o res para sbr o qnt lemos
        res = read (p[0], &buffer, sizeof(buffer));
        
        close (p[0]);
        _exit(0);
    default:
        // codigo pai
        // fechar o descriptor de leitura do pai
        close(p[0]);
        write(p[1], &line, strlen(line));
        // fechar o fd de escrita do pai, pois nao preciso mais dele
        close(p[1]);

        wait (&status);
    }
    return 0;
}

int main(){
    int r;
    r = pai2filho();
    return r;
}
