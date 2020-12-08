// Implements a dictionary's functionality
#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];   // for word + \0 the null byte
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;   // since it is a dictionary, in order the reduce O(n), we have to create 26 buckets to fit words into.


// Hash table
node *table[N];
int wordsfound=0;
unsigned int hash_value;







// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //hash the word to get hash value
    hash_value = hash(word);
    //access the linked list  
    node *cursor = table[hash_value];
//go through the linked list
    while (cursor != NULL)
    {
        //check if the word matches
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
//move cursor to next node
        cursor = cursor->next;
    }
return false;
}



// Hashes word to a number
unsigned int hash(const char *word)
{


    // hash function is taken from here :http://www.cse.yorku.ca/~oz/hash.html
    unsigned long hash = 5381;
    int c;
    while ((c = toupper(*word++)))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N;
}






// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{   

    // We opened the dictionary into read mode.
     FILE *dict = fopen(dictionary,"r");
     char *word = malloc(LENGTH+1);   // creating a buffer for fscanf, for allocating space for each word read from dictionary

     if(word == NULL){
         printf("Could not load %s\n",dictionary);         
         fclose(dict);
         return EXIT_FAILURE;
     }

     while(fscanf(dict, "%s", word)!=EOF) // reading each word from the file until it is the EndOfFile!.
     {         
         node *n = malloc(sizeof(node));    // allocating enough memory for the next node, since it is a loop.
         // checking wehether malloc returns null
         if(n==NULL){
             printf("could not initialize enough memory space for this action\n");
             free(n);
             return EXIT_FAILURE;
         }
         // copyting the word into the allocated buffer memory
         strcpy(n->word, word);   // copyting the word itself into n->word. strcopy first argument is the destionation the second one is source. its like = .
         wordsfound+=1;
         n->next= table[hash(word)];
         table[hash(word)]=n;

     }
    // takes a file to open if loaded, return 0 else return false.
    free(word);
    fclose(dict);
    return EXIT_SUCCESS;
}
// we iterated through all the words in the dictionary, loaded them into memory into the hash table, now we are ready to process the spell-check











// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Check if there are any words
    if (wordsfound > 0)
    {
        // Return count
        return wordsfound;
    }
    // Else
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Iterate through buckets
    for (int i = 0; i < N; i++)
    {
        // Set cursor to this each bucket location  
        node *cursor = table[i];
// If cursor is not NULL, free  
        while (cursor)
        {
            // Create temp 
            node *tmp = cursor;
            // Move cursor to next node
            cursor = cursor->next;
            // Free up temp
            free(tmp);
        }
// If cursor is NULL
        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }
    }
    return false;
}