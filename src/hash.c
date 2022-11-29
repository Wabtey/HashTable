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

     if (MAX_ENTRIES > 0)
     {

          hash_table *ht = (hash_table *)malloc(sizeof(hash_table));
          ht->hsize = MAX_ENTRIES;
          ht->htable = (word_list *)malloc(ht->hsize * sizeof(word_list));
          // pas la place pour le tableau / allocation mal passée
          if (ht->htable == NULL)
          {
               return NULL;
          }

          for (int i = 0; i < ht->hsize; i++)
          {
               word_list wl;
               wl.first_word = NULL;
               wl.last_word = NULL;
               ht->htable[i] = wl;
          }

          // hash_table * htp = &ht;
          return ht;
     }
     else
     {
          return NULL;
     }
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
int search_word(char word[],
                listfile_entry *filelist,
                hash_table *htable_ptr)
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

void update_table(hash_table *htable_ptr,
                  char word[],
                  char filename[],
                  int file_index)
{

     // on récupère la bonne adresse dans la hashtable
     int key = hashcode(word, htable_ptr->hsize);
     word_list *wl = &(htable_ptr->htable[key]);

     // on récupère le premier mot de la liste de mot stocké
     word_entry *current = wl->first_word;
     // on parcourt la liste
     while (current != NULL)
     {
          // Il est déjà présent dans la liste
          if (strcmp(current->word, word) == 0)
          {
               current->times += 1;
               printf("le mot %s est déjà présent, il est maintenant présent %d fois\n", word, current->times);
               return;
          }
          current = current->next;
     }
     // Sinon on ne l'a pas trouvé dans la liste
     // on l'ajoute au début de la liste
     printf("on ajoute le mot %s \n", word);
     word_entry *newWord = malloc(sizeof(word_entry));
     strcpy(newWord->word, word);
     newWord->times = 1;
     newWord->in_file = file_index;
     newWord->next = wl->first_word;
     wl->first_word = newWord;
     return;
}

/**
   print table contents

   parameters :
   htable_ptr : pointer to hash table
   filelist   : pointer to table of files
*/
void print_table(hash_table *htable_ptr,
                 listfile_entry *filelist)
{
     int hsize = htable_ptr->hsize;
     for (int i = 0; i < hsize; i++)
     {
          word_list *wl = &(htable_ptr->htable[i]);
          if (wl->first_word != NULL)
          {
               printf("word_list numero %d \n", i);
               word_entry *current = wl->first_word;
               while (current != NULL)
               {
                    printf("%s", current->word);
                    current = current->next;
               }
          }
     }
}

/**
   free hash table

   parameters :
   htable_ptr : pointer to hash table
*/
void free_table(hash_table *htable_ptr)
{

     // TO BE COMPLETED
}

// ------------------------------------------------------------------------
// inner functions definitions
// ------------------------------------------------------------------------

// TO BE COMPLETED
