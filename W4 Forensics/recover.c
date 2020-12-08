#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>


// the program should only take one argument, which is the name of the forensic image!
// faulty usage must return 1 and urge the user
// if forensic image cannot be read, the user must be prompted so.
// names of the rescued files should be consecutive triple digit integer names - 000.jpg, 001.jpg etc, 
// is use malloc, no memory leak should happen!

int main(int argc, char *argv[])
{
 

 // lets check the argcs

 if(argc !=2){
     fprintf(stderr,"Program takes only one parameter which is the forensic image.\n");
     return EXIT_FAILURE;
 }

FILE *forensic= fopen("argv[1]", "r");
if(forensic==NULL){
    fprintf(stderr,"File %s could not be opened\n",argv[1]);
}

// lets define some generic values to use iteratively


FILE *image;  // this is for the new file.
int counter = 0; // number of founded items
char name[8]; // 000.jpg + \0
char *buffer = malloc(512); // This is the 512 byte buffer are to read and write the chunks.









fclose(image);
fclose(forensic);
free(buffer);

}