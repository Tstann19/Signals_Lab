/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int working = 0;
time_t start;
int count = 0;


void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  working = 1; //exit after printing
  count++;
  alarm(5);
}

void timer(int signum)
{
  time_t end = time(NULL);
  double totalTime = difftime(end, start);

  printf("\nTotal SIGALRM signals received: %d\n", count);
  printf("Total time: %.0f seconds\n", totalTime);
  exit(0);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT, timer);

  start = time(NULL);

  alarm(5); //Schedule a SIGALRM for 5 seconds
  while(1){
    pause();
    if (working){
      working = 0;
      printf("Turing was right!\n");
    }
  } //busy wait for signal to be delivered
  return 0; //never reached
}