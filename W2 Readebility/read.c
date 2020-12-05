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
    int letter;
    int sentence;
    int word;
    double readability= 0.0588 * L - 0.296*S - 15.8;



}