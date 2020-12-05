#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>


int main(void)
{
    
    printf("How many steps you want to build mario pyramid with?\n");
    int number;
    int line;
    scanf("%d",&number);
    printf("number is %d\n",number);
    if(number<1 || number > 20)
    {
        printf("Please give a value between 1 and 20\n");
         sleep(1);
        printf("Exiting...");
        sleep(1);
        return EXIT_FAILURE;
    }else if (number>='a' && number<= 'Z')
    {
        printf("Please submit a positive real number between 1 and 20\n");
         sleep(1);
        printf("Exiting...");
        sleep(1);
        return EXIT_FAILURE;
        
    }
    



    printf("Initializing....\n");
    sleep(1);
    printf("Drawing a twin pyramid with the given height of %d\n",number);
    
    for(line=0;line<number;line++)
    {
        int spacing = number - line -1;
        int hash = line +2;

        for(int j =0; j<spacing;j++)
        {
            printf(" ");
        }

        for(int t=0; t<hash;t++)
        {
            printf("#");
        
        }
        sleep(1);
        printf("\n");
    }
  
}
