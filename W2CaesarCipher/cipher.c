#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#include <ctype.h>

int main( int argc, char *argv[] )
{

    printf("The Application %s is waiting for your command \n", argv[0]);
    sleep(1);
    
    int key;

    if(argc<2)
    {
      printf("Too few positional arguments\n");
      printf("Usage: ./caesar key \n");
      return EXIT_FAILURE;
    }
    else if( argc > 2 ) 
    {
      printf("Too many positional arguments\n");
      printf("Usage: ./caesar key \n");
      return EXIT_FAILURE;
    }
    else if (argc ==2)
    {
        if (!isdigit(atoi(argv[1])))
        {
            key = atoi(argv[1]);

            if(key>0){
                printf("key is %d\n",key);
                key = atoi(argv[1]);

            }
            else{
                printf("Key cannot be a negative integer. Given parameter is %d\n",key);
                return EXIT_FAILURE;
            }
            
        }else{
            printf("Given argument is not a positive integer\n");
            EXIT_FAILURE;
        }
    }
 

    

}

