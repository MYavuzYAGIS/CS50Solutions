#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <unistd.h>
#ifndef __cplusplus
// bool is not defined in C , so we are adding it.
typedef unsigned char bool;
static const bool False = 0;
static const bool True = 1;
#endif
// now we can use bool

#define MAX 9
// adding the prototypes
bool vote(char *name);
void winner(void);

// Lets create a constructor for the candidate
typedef struct{
    char *name;
    int votes;
}
candidate;
// lets crate an array for the all the candidates:
candidate candidates[MAX];    // We created an array, constructed from the data type we defined called candidate.  Max is the maximum amount of the candidate it can hold.
// lets create a candidate count which cannot pass MAX.
int candidate_count;





// Lets initialize the Main function
int main(int argc, char *argv[])
{


candidate_count = argc-1;

if(candidate_count>MAX){
    printf("Maximum amount of candidates are exceeding, maximum allowed amount is %i\n",MAX);
    return EXIT_FAILURE;
}


// checking invalid use cases 

    if (argc < 2)
    {
        printf("Too few arguents are supplied\n");
        printf("Use Case : plurality[candidate ..]\n");
        return EXIT_FAILURE;
    }

    for(int i=0; i<candidate_count;i++)
    {
        candidates[i].name = argv[i+1];   // since argv0 is the name of the prgram, we nhave to start assigning from argv[i+1] and this will be the name of the candidate
        candidates[i].votes=0;  // candidate starts with 0 vote count , for the purpose of fair play :)
    }


    // Now lets get some voter count : 

    int voter_count;
    printf("How many voters there are in the system?\n");
    sleep(1);
    printf("=>");
    fgets(voter_count, MAX, stdin);

    for (int i=0; i<voter_count;i++)
    {
         printf("Please provide a Name to vote for :\n");
         char *name;
         name = (char *)malloc(MAX);
        fgets(name, MAX, stdin);
         // checking for invalid vote:
         if(!vote(name)){
             printf("No such candidate");
             free(name);
             return EXIT_FAILURE;
         }
    }

    print_winner();

       


return EXIT_SUCCESS;

}


bool vote(char *name){
    
}


int print_winner(void){

}