int aux(){
// (::::::)
    if ((fd= open ("fifo",O_RDONLY))==-1){
        perror("open");
        return -1;
    }else {
        printf("[DEBUG]opened fifo for reading\n");
    }
    if((fd_write("fifo",O_WRONLY))==-1){
        perror("write");
        return -1;
    }
     else {
        printf("[DEBUG]opened fifo for writing\n");
    }
    while (bytes_read=read(fd,buf,MAX_ARG_SIZE))>0){
        write(logfile,buf,)
    }
}