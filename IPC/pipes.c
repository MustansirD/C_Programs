#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{
    int fds[2];
    pipe(fds);
    printf("[%d]\n",fds[0]);
    printf("[%d]\n",fds[1]);
    
    int childpid = fork();
    if(childpid == -1)
    {
        fprintf(stderr,"fork error\n");
        exit(1);
    }
    
    if (childpid == 0)
    {
        close(fds[0]);
        char str[] = "hello";
        fprintf(stdout,"CHILD:waiting for 2 sec...\n");
        sleep(2);
        fprintf(stdout,"CHILD:writing to daddy\n");
        write(fds[1],str,strlen(str) + 1);
        
    }
    else
    {
        close(fds[1]);
        char buff[32];
        fprintf(stdout,"PARENT:reading from child\n");
        int num=read(fds[0],buff,32);
        fprintf(stdout,"PARENT:rcvd from child[%s]\n",buff);
    }
    
    return 0;
}