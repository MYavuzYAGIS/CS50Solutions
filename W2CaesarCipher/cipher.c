#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#include <ctype.h>
#define MAX_NAME_SZ 256


int main( int argc, char *argv[] )
{

    printf("The Application %s is waiting for your command \n", argv[0]);
    sleep(1);
    
    
    char *plain;
    // initializing the variable
    plain= (char *) malloc(256);
    if(plain==NULL){
        printf("No Memory");
        return EXIT_FAILURE;
    }
    int key;
    
    // Argument Filtering. Now It accepts only positive integers
    if(argc<2)
    {
      printf("Too few positional arguments\n");
      printf("Usage: ./caesar key \n");
      free(plain);
      return EXIT_FAILURE;
      
    }
    else if( argc > 2 ) 
    {
      printf("Too many positional arguments\n");
      printf("Usage: ./caesar key \n");
      free(plain);
      return EXIT_FAILURE;
      
    }
    else if (argc ==2)
    {
        if (!isdigit(atoi(argv[1])))
        {
            key = atoi(argv[1]);
            // Controlling whether the key is greater than or equal to 26. It will return the remainder as real key value
            // the best condition, the value is between 1 and 26
            if(key>0 && key <=26){
                printf("key is Secured!\n");
                key = atoi(argv[1]);

            }
            // assigned key is greater than 26, thus, rotating it and reassigining to key value so there is no overflow in the ascii table.
            else if(key > 26)
            {
                key = key %26;
                key = atoi(argv[1]);
            }
            else{
                printf("Key cannot be a negative integer or 0. Given parameter is %d\n",key);
                free(plain);
                return EXIT_FAILURE;
            }
            
        }else{
            printf("Given argument is not a positive integer\n");
            EXIT_FAILURE;
        }
    }
 
        printf("Ceasar! Caesar! I need the plaintex to cipher against the barbarian Germens!\n");
        sleep(2);
        printf("What is the top secret information you want to be encrypted?\n");
        printf("\n");
        printf("=>");
        fgets(plain, MAX_NAME_SZ,stdin);
        printf("I will cipher the following text %s\n",plain);
        
        




free(plain);
return EXIT_SUCCESS;
}

