#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#define MAX_NAME_SZ 256
double read(char *text);
int main(void){

  char *text=NULL;  
  printf("Please submit a text to grade the readability..\n");
  sleep(1);
  // memory allocation for the text variable.
  text = (char *)malloc(256);
  // safety check on the memory allocation process.
  if (text == NULL)
  {
      free(text);
      printf("not enough memory space to allocate");
      return EXIT_FAILURE;
  }
  fgets(text, MAX_NAME_SZ,stdin);
  printf("%s\n",text);
  read(text);

















free(text);
return EXIT_SUCCESS;
}


double read(char *text){
    double L;
    double S;
    int letter=0;
    int sentence=0;
    int word=1;  // I started word count 1 because word count == spacecount +1
    double readability= 0.0588 * L - 0.296*S - 15.8;

    if(strlen(text)<=1){
        printf("Do not play smart, give me a real text to analyze");
        return EXIT_FAILURE;
    }else{


    for(int i=0; i<strlen(text);i++){
        if(text[i]==' '){
            word = word +1;
        }else if(text[i] == '.' || text[i] == '?' || text[i] == '!')   // denotes end of the sentence so sentence ++;
        {
            sentence ++;
        }else{
            letter++; // if not space and not sentence end, We assume it is a letter.
        }
        
    }
    }





}