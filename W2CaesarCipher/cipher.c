#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>

int main( int argc, char *argv[] )
{

    printf("The Application %s is waiting for your command \n", argv[0]);
    sleep(1);
    printf("Please select a functionality and proceed");


    if( argc == 2 ) {
      printf("You selected to %s\n", argv[1]);
   }
   else if( argc > 2 ) {
      printf("Too many positional arguments\n");
      printf("cipher enc || cipher decr \n");
   }
   else {
      printf("Too few positional arguments\n");
      printf("cipher enc || cipher decr \n");
   }





}