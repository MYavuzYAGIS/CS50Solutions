#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
int read(char *text);
#define MAX_NAME_SZ 256


int main(void)
{
  char *text=NULL;  
  printf("Please submit a text to grade the readability..");
  sleep(2);

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


int read(char *text){
    printf("%s\n",text);    
    return EXIT_SUCCESS;
}