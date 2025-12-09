/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int working = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  working = 1; //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(5); //Schedule a SIGALRM for 5 seconds

  //busy wait for signal to be delivered
  while(!working){
    pause();
  } 
  printf("Turing was right!\n");
  return 0; //never reached
}