// ficha
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){

    int res = 0;
    int fork_ret, wait_ret, status;
    
    char buffer;
    char line[1024];


    int ifd = open("/etc/passwd",O_RDONLY);
    int ofd = open("saida.txt",O_CREAT | O_TRUNC |O_WRONLY, 0666);
    int ifd = open("/etc/passwd",O_CREAT | O_TRUNC |O_WRONLY, 0666);
}

