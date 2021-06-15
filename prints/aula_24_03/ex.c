
#include <stdio.h>
#include <unistd.h>

int func (){

    int ret;

    char* exec_args [] = {"/bin/ls","-l",NULL};

    printf("msg 1\n");

    // ret = execl("/bin/ls","/bin/ls","-l",NULL);
    // ret = execlp("ls","/bin/ls","-l",NULL);
    ret = execvp("ls",exec_args);

    printf("msg 2\n");

    perror("reached return");
    return 0;
}

int main (int argc, char** argv){




    return 0;
}