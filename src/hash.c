#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h" // global functions declarations

// ------------------------------------------------------------------------
// inner functions declarations
// ------------------------------------------------------------------------

// TO BE COMPLETED

//------------------------------------------------------------------------
// global functions definitions
//------------------------------------------------------------------------

/**
   create and initialize hash table

   returns : pointer to table or NULL if creation error
*/
hash_table *
create_table()
{

  // TO BE COMPLETED

  return NULL; // TODO
}

/**
   search a word in table ; print word if found, with number of occurrences
   and file where word is found

   parameters :
   word : the word to look for
   filelist   : pointer to table of files
   htable_ptr : pointer to hash table

   returns : true if found, false otherwise
*/
int
search_word(char word[],
	    listfile_entry * filelist,
	    hash_table * htable_ptr)
{

  // TO BE COMPLETED

  return 0;
}

/**
   lookup for word in table and update table accordingly

   parameters :
   htable_ptr : pointer to hash table
   word : word to be added into the hash table
   filename   : filename from where the word was read
   file_index:  the position where the filename has been stored
*/

void update_table(hash_table * htable_ptr,
                   char word[],
                   char filename[],
                   int file_index)
{

  // TO BE COMPLETED

}

/**
   print table contents

   parameters :
   htable_ptr : pointer to hash table
   filelist   : pointer to table of files
*/
void
print_table(hash_table * htable_ptr,
	    listfile_entry * filelist)
{

   // TO BE COMPLETED

}


/**
   free hash table

   parameters :
   htable_ptr : pointer to hash table
*/
void
free_table(hash_table * htable_ptr)
{

  // TO BE COMPLETED

}

// ------------------------------------------------------------------------
// inner functions definitions
// ------------------------------------------------------------------------

// TO BE COMPLETED
