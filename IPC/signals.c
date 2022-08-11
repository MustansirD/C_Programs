#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void handle_user_signals(int signal)
{
    switch (signal)
    {
        case SIGUSR1:   printf("USR1\n");
                        break;
        case SIGUSR2:   printf("USR2\n");
                        break;
        default:        printf("Unsupported\n");
                        break;
    }   
}

void handle_sigint(int signal)
{
    printf("Interrupt\n");
}

void handle_sigkill(int signal)
{
    printf("Kill\n");
    exit(0);
}

int main(int argc, char *argv[])
{
    signal(SIGUSR1,handle_user_signals); 
    signal(SIGUSR2,handle_user_signals);
    signal(SIGINT,handle_sigint);
    signal(SIGKILL,handle_sigkill);
    while(1);
    return 0;
}