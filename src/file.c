#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "functions.h" // extern functions declarations

// ------------------------------------------------------------------------
// inner functions declarations
// ------------------------------------------------------------------------

// TO BE COMPLETED

//------------------------------------------------------------------------
// global functions definitions
//------------------------------------------------------------------------

/**
   Create and initialize file table of capacity maxfiles

   parameters :
   maxfiles : capacity of file table

   returns : pointer to table or NULL in case of error
 */
listfile_entry *
create_filelist(int maxfiles)
{
     listfile_entry *lf = (listfile_entry *)malloc(maxfiles * sizeof(listfile_entry));

     if (lf == NULL)
     {
          return NULL;
     }

     for (int i = 0; i < maxfiles; i++)
     {
          lf[i].loaded = 0;
     }

     return lf;
}

/**
   add words from file to table
   - checks if the file has already been loaded
   - updates the file table (if file not already loaded)
   - reads every word in the file (idem)
   - updates the hash table (idem)

   parameters :
   filename   : name of file :)
   filelist   : pointer to table of files
   htable_ptr : pointer to hash table

   returns :
    1 if file already present in table
    2 if no space left in filelist
   -1 if file doesn't exist or can't be read
   -2 if allocation error
    0 if everything ok
*/
int add_file(char filename[],
             listfile_entry *filelist,
             hash_table *htable_ptr)
{

     // TODO rajouter -1 -2 en exception

     int index_entry = -1;
     for (int i = 0; i < sizeof(filelist); i++)
     {
          if (filelist[i].loaded == 0)
          {
               index_entry = i;
          }
          if (strcmp(filelist[i].filename, filename) == 0)
          {
               printf("already present in table");
               return 1;
          }
     }
     if (index_entry == -1)
     {
          printf("no space left in filelist");
          return 2;
     }
     else
     {
          filelist[index_entry].loaded = 1;
          strcpy(filelist[index_entry].filename, filename);
          FILE *fichier = NULL;
          fichier = fopen(filename, "r");
          char word[MAX_LENGTH];
          if (fichier == NULL)
          {
               perror("Error opening file"); // print error
               return (-1);
          }

          fgets(word, MAX_LENGTH, fichier);
          while (!feof(fichier))
          {
               update_table(htable_ptr, word, filename, index_entry);
               fgets(word, MAX_LENGTH, fichier);
          }
          fclose(fichier);
     }

     return 0; // all fine
}

/**
   remove file from file table

   parameters :
   filename   : name of file to remove
   filelist   : pointer to table of files
   htable_ptr : pointer to hash table

   returns :
   -1 if file not in table
    0 if file removed
*/
int remove_file(char filename[],
                listfile_entry *filelist,
                hash_table *htable_ptr)
{
     for (int i = 0; i < sizeof(filelist); i++)
     {
          if (strcmp(filename, filelist[i].filename))
          {
               filelist[i].loaded = 0;
               FILE *fichier = NULL;
               fichier = fopen(filename, "r");
               char word[MAX_LENGTH];
               while (!feof(fichier))
               {
                    fgets(word, MAX_LENGTH, fichier);
                    update_table(htable_ptr, word, filename, i);
               }
               fclose(fichier);
               return 0;
          }
     }

     return -1;
}

/*
  print file table (only loaded files)

  parameters :
   filelist : pointer to table of files
*/
void print_list(listfile_entry *filelist)
{
     for (int i = 0; i < sizeof(filelist); i++)
     {
          if (filelist[i].loaded == 1)
          {
               printf("%s\n", filelist[i].filename);
          }
     }
}

/**
   free file table

parameters :
   filelist   : pointer to table of files
*/
void free_filelist(listfile_entry *filelist)
{
     // TO BE COMPLETED
}

// ************************************************************************
// inner functions
// ************************************************************************

// TO BE COMPLETED
