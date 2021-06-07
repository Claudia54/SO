#include <signal.h>
#include <sys/types.h>

//ex1--fazer CTRLC MTS 

int signhadler (){

}


int multigrep(){
    pid_t pid =fork();
    while (){
        kill(pid,SIGKILL);


    }

}

int main (){
    //array de pids
    int found=0;
    int status=0;
    int pid;
    int pid_found=-1;
    while(!found && pid=wait(&status)>0){}
    if (found===1){
      for(int i=0, i<files_count;i++){
          if(WIFEEXIT)
          while(WEXIT....)
          if(pids[i]!=pid_found){
              printf("killing process %d\n",pids[i]);

              if(pids[i]>0){
                  kill(pid,SIGKILL);
              }
              waitpid(pids[i],&status,0);

          }
      }
    }
}







//multipgrep

