#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>


// how to open a file ? 
// FILE* ptr = fopen("name.ext","mode- r or a or w");   writing will overwrite all the file and delete all the files whereas append will just append.
// fclose(ptr);
// fgetc()!!  reads and returns athe next character from the file pointed to . it should be always in r mode!! 
// char ch = fgetc(ptr); FILE MUST HAVE BEEN OPENED FOR READING! NOT FOR WRITING MESELA!!
// So how can we read all the characters from a file ? a loop ofc!
/*  
char ch;
while((ch = fget(ptr))!= EOF){     // EOF is a special character which basically means EndOfFile!. 
    printf("%c",ch);  hepsini okur 
}

*/

// What about fputc()?
// writes or appends the specified charated to the pointed file. it should be opened in either with w or a ! yani it should have been opened with writing or appending!
// fputc(character, file pointer);
// fputc("A",ptr)

// duplicating the linux command cp:
/* 
    FILE* ptr = fopen("filename", "r");
    FILE *ptr2 =fopen("filename2", "w");
    while ((ch= fgetc(ptr))!=EOF){
        fputc(ch,pt2);
    }

 */

// fread()  // generic version of fgetc()  reads quantity of the size from the file pointed and stores in a memory in a buffer ponted to by buffer
// fread(buffer, size, qty, filepointer);
// for example we declare an array of 10 integers.
// FILE* ptr = fopen("filename", "r");
//int array[10];
// fread(arr, sizeof(int),10,ptr);  
// burda, ptr isimli file actik evvelden, burdan 10 element okuyacagiz mesela dimi. onun icin array actik, one size of int kadar memory verdik. 4x10 = 40 byte.  sonra dedik ki ptrda okudugun 40 bytei oraya yaz.
// we can also dynamically allocate buffer using malloc:
/*
FILE* ptr = fopen("filename", "r");
double *arr2 = malloc(sizeof(double)*80);
fread(arr2, sizeof(double),80,ptr);  // collecting 640 bytes of informatin (double = 8 bytes), stroring in arr.


we can also take one character using fread!


FILE* ptr = fopen("filename", "r");
char c;
fread(&c, sizeof(char),1,ptr);      ama burda catch, memory pointer aradigimiz icin c yerine &c vermemizlazim fread icinde.


FWRITE

freadde yaptigimiz her seyi fwrite da yazabiliriz. 

fwrite(buffer, size, quantity, filepointer)  freadin aynisi sadece write functon.

int array[10];
fwrite(arr, sizeof(int),10,ptr);



*/
