/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int working = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  working = 1;  
  alarm(5);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(5); //Schedule a SIGALRM for 5 seconds
  while(1){
    pause();         
    if (working) {
      printf("Turing was right!\n"); 
      working = 0;                   
    }
  } 
  return 0; //never reached
}