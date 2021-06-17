#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

#include "argus.h"

char* tasks[2048];
int taskStatus[2048];
int exitStatus[2048];
int execTimes[2048];
char commTimes[2048];
int monitors[2048];
int pids[2048][32];
int numPids[2048];
int lastProcess = 0;
int tExec = -1;
int tInac = -1;
int iTask = 0;

int pid;
int pidOut;

int main(int argc, char const *argv[]) {
    mkfifo("client_server_fifo", 0644);
    mkfifo("server_client_fifo", 0644);
    
    //int *iTask = malloc(sizeof(int));
    //*iTask = 0;
    //alarm(1);

    while(1) {
        char* buffer = calloc(MESSAGESIZE, sizeof(char));
        int client_server_fifo = open("client_server_fifo", O_RDONLY);
        int server_client_fifo = open("server_client_fifo", O_WRONLY);
        
        if(read(client_server_fifo, buffer, MESSAGESIZE)!=0){ // le a msg do cliente
            
        tasks[iTask] = strdup(buffer);
        
        
        if(strncmp(buffer, "transform", 9) == 0){
            char command[MESSAGESIZE];
            strcpy(command, buffer + 9);
            //*iTask = *iTask + 1;
            //taskStatus[*iTask] = 0;
            

            char message[64];
            sprintf(message, "pending\n");
            
            write(server_client_fifo, message, strlen(message));
            sprintf(message, "processing\n");
            
            write(server_client_fifo, message, strlen(message));
            close(server_client_fifo);
            char* token;
            char* args[1000];
            int i = 0;
            char* rest = command;
            char* output1="outputTMP1.m4a";
            char* tmp;
            char* output2="outputTMP2.m4a";

            while((token = strtok_r(rest, " ", &rest))) {
                if(i == 0) {
                    args[0] = strdup(token);
                    i++;
                } else {
                    args[i] = strdup(token);
                    i++;
                }
            }


            int status;
            for (int j=2; j<i;j++){
            
            waitpid(pid,&status,0);
            
                if (strcmp(args[j],"alto") == 0){

                    int pipes[2];
                    
                    int lock;

                
                    if((pid = fork()) == 0) {
                        int ifd;
                        int ofd;
                        
                        if(i==3){
                            ifd = open(args[0], O_RDONLY, 0666);
                            ofd = open(args[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
                            
                        }else if(j==2){
                            ifd = open(args[0], O_RDONLY, 0666);
                            ofd = open(output1, O_CREAT | O_TRUNC | O_WRONLY, 0666);
                            
                        }else if(j==i-1){
                            ifd = open(output2, O_RDONLY, 0666);
                            ofd = open(args[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
                        }else{
                            ifd = open(output1, O_RDONLY, 0666);
                            ofd = open(output2, O_CREAT | O_WRONLY, 0666);
                            
                            tmp = output1;
                            output1 = output2;
                            output2 = tmp;
                        }

                        int res = dup2(ifd,0);
                        res = dup2(ofd,1);
                        
                        //fcntl(ofd, F_SETOWN, lock);
                        //fcntl(ofd, F_SETFL, O_ASYNC | O_RDONLY);
                        
                        
                        close(ifd);
                        close(ofd);
                        res = execl("./bin/aurrasd-filters/aurrasd-gain-double","./bin/aurrasd-filters/aurrasd-gain-double",NULL);
                        
                       }
                       
                }else if (strcmp(args[j],"rapido") == 0){

                    int pipes[2];
                    int pid;
                  
                    if((pid = fork()) == 0) {
                        int ifd;
                        int ofd;

                        if(i==3){
                            ifd = open(args[0], O_RDONLY, 0666);
                            ofd = open(args[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
                            
                        }else if(j==2){
                            ifd = open(args[0], O_RDONLY, 0666);
                            ofd = open(output1, O_CREAT | O_TRUNC | O_WRONLY, 0666);
                            
                            
                        }else if(j==i-1){
                            ifd = open(output2, O_RDONLY, 0666);
                            ofd = open(args[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
                        }else{
                            ifd = open(output1, O_RDONLY, 0666);
                            ofd = open(output2, O_CREAT | O_WRONLY, 0666);
                            
                            tmp = output1;
                            output1 = output2;
                            output2 = tmp;
                        }
                        int res = dup2(ifd,0);
                        res = dup2(ofd,1);
                        close(ifd);
                        close(ofd);
                        res = execl("./bin/aurrasd-filters/aurrasd-tempo-double","./bin/aurrasd-filters/aurrasd-tempo-double",NULL);
                        
                       }
                }else if (strcmp(args[j],"lento") == 0){

                    int pipes[2];
                    int pid;
                  
                    if((pid = fork()) == 0) {
                        int ifd;
                        int ofd;

                        if(i==3){
                            ifd = open(args[0], O_RDONLY, 0666);
                            ofd = open(args[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
                            
                        }else if(j==2){
                            ifd = open(args[0], O_RDONLY, 0666);
                            ofd = open(output1, O_CREAT | O_TRUNC | O_WRONLY, 0666);
                            
                            
                        }else if(j==i-1){
                            ifd = open(output2, O_RDONLY, 0666);
                            ofd = open(args[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
                        }else{
                            ifd = open(output1, O_RDONLY, 0666);
                            ofd = open(output2, O_CREAT | O_WRONLY, 0666);
                            
                            tmp = output1;
                            output1 = output2;
                            output2 = tmp;
                        }
                        int res = dup2(ifd,0);
                        res = dup2(ofd,1);
                        close(ifd);
                        close(ofd);
                        res = execl("./bin/aurrasd-filters/aurrasd-tempo-half","./bin/aurrasd-filters/aurrasd-tempo-half",NULL);
                        
                       }
                }else if (strcmp(args[j],"eco") == 0){

                    int pipes[2];
                    int pid;
                  
                    if((pid = fork()) == 0) {
                        int ifd;
                        int ofd;

                        if(i==3){
                            ifd = open(args[0], O_RDONLY, 0666);
                            ofd = open(args[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
                            
                        }else if(j==2){
                            ifd = open(args[0], O_RDONLY, 0666);
                            ofd = open(output1, O_CREAT | O_TRUNC | O_WRONLY, 0666);
                            
                            
                        }else if(j==i-1){
                            ifd = open(output2, O_RDONLY, 0666);
                            ofd = open(args[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
                        }else{
                            ifd = open(output1, O_RDONLY, 0666);
                            ofd = open(output2, O_CREAT | O_WRONLY, 0666);
                            
                            tmp = output1;
                            output1 = output2;
                            output2 = tmp;
                        }
                        int res = dup2(ifd,0);
                        res = dup2(ofd,1);
                        close(ifd);
                        close(ofd);
                        res = execl("./bin/aurrasd-filters/aurrasd-echo","./bin/aurrasd-filters/aurrasd-echo",NULL);
                        
                       }
                }else if (strcmp(args[j],"baixo") == 0){

                    int pipes[2];
                    int pid;
                  
                    if((pid = fork()) == 0) {
                        int ifd;
                        int ofd;

                        if(i==3){
                            ifd = open(args[0], O_RDONLY, 0666);
                            ofd = open(args[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
                            
                        }else if(j==2){
                            ifd = open(args[0], O_RDONLY, 0666);
                            ofd = open(output1, O_CREAT | O_TRUNC | O_WRONLY, 0666);
                            
                            
                        }else if(j==i-1){
                            ifd = open(output2, O_RDONLY, 0666);
                            ofd = open(args[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
                        }else{
                            ifd = open(output1, O_RDONLY, 0666);
                            ofd = open(output2, O_CREAT | O_WRONLY, 0666);
                            
                            tmp = output1;
                            output1 = output2;
                            output2 = tmp;
                        }
                        int res = dup2(ifd,0);
                        res = dup2(ofd,1);
                        close(ifd);
                        close(ofd);
                        res = execl("./bin/aurrasd-filters/aurrasd-gain-half","./bin/aurrasd-filters/aurrasd-gain-half",NULL);
                        
                       }
                }
                
            }

            //taskStatus[*iTask] = 1;
            


            for(size_t j = 0; j < i; j++) free(args[j]);


        }else if(strncmp(buffer, "status",6) == 0){
            //printf("STATUS");
            if((pidOut = fork()) == 0) {
            //int server_client_pipe = open("server_client_fifo", O_WRONLY);
            for (int i = 0; i < iTask; i++){
            
            char message[64];
            //if (taskStatus[i])
            sprintf(message, "task #%d: %s\n",i+1,tasks[i]);
            //fprintf(1,"task");

            write(server_client_fifo, message, strlen(message));
            }
            }
        }else {
            char buf[32];
            strcpy(buf, "\nComando inválido.\n\n");
            write(server_client_fifo, buf, strlen(buf));  
        }
        iTask++;
        }
        free(buffer);
        close(server_client_fifo);
        close(client_server_fifo);
       // printf("%d\n",*iTask);
    
    }
    return 0;
}