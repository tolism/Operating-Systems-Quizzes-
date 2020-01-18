//Child process and piping 

void child(int *fd , char **cmd){
close(fd[0]);
dup2(fd[1],1);
dup2(fd[1],2);
if(execvp(cmd[0] , cmd)<0){
  //execvp(*cmd, cmd)
  fprintf(stderr, "ERROR\n");
}
}
