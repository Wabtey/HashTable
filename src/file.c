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
  listfile_entry * lf = (listfile_entry *)malloc(maxfiles*sizeof(listfile_entry));

  if (lf == NULL){
  return NULL;
  }

  for(int i = 0 ; i<maxfiles ; i++){
      strcpy(lf[i].filename , "");
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
int
add_file(char filename[],
	 listfile_entry * filelist,
	 hash_table * htable_ptr)
{
  int index_entry=-1;
  for (int i =0 ; i<sizeof(filelist); i++){
    if(filelist[i].loaded == 0){
      index_entry = i;
    }
    if (strcmp(filelist[i].filename, filename)==0){
      if(filelist[i].loaded == 1){
        printf("already present in table");
        return 1;
      }
      else{// présent mais pas loaded
        filelist[i].loaded = 1;
        FILE * fichier = NULL;
        fichier = fopen(filename,"r");
        char c;
        char word[MAX_LENGTH];
        if(fichier == NULL){
          perror("Error opening file"); // print error
          return(-1);
        }
        strcpy(word, "");
        do{
          c = (char)fgetc(fichier);
          // space       new line     null       tab
          if(c == ' ' || c == '\n' ||  c == '\0' || c =='\t' || c==',' || c=='.' || c =='(' || c == ')' || c=='?' || c=='!'){
            update_table(htable_ptr,word,filename,index_entry);
            strcpy(word, "");
          }
          else
          {
            strcat(word, &c); //Keeps track of current word
          }

        }while(c != EOF);

        fclose(fichier);
        return 0;
      }
    }
  }
  if(index_entry==-1){
    printf("no space left in filelist");
    return 2;
  }
  else{
    FILE * fichier = NULL;
    fichier = fopen(filename,"r");


    //le fichier n'xiste pas
    if(fichier == NULL){
      perror("Error opening file"); // print error
      return(-1);
    }
    char c;
    char word[MAX_LENGTH];
    filelist[index_entry].loaded=1;
    strcpy(filelist[index_entry].filename,filename);
    strcpy(word, "");
    do{
      c = (char)fgetc(fichier);
      // space       new line     null       tab
      if(c == ' ' || c == '\n' ||  c == '\0' || c =='\t' || c==',' || c=='.' || c =='(' || c == ')' || c=='?' || c=='!'){
        if(strcmp(word , "")!=0){
          update_table(htable_ptr,word,filename,index_entry);
          strcpy(word, "");
        }
      }
      else
      {
        strcat(word, &c); //Keeps track of current word
      }
      //characterfunction(c);
    }while(c != EOF);

    fclose(fichier);

  }

// rajouter -1 -2 en exception


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
int
remove_file(char filename[],
	    listfile_entry * filelist,
	    hash_table * htable_ptr)
{

  // on parcourt l'ensemble des files
  for (int i = 0; i<sizeof(filelist); i++){
      // si le file est présent est chargé
      if((strcmp(filename, filelist[i].filename)==0) && (filelist[i].loaded==1)){
        // on ne le load plus
        filelist[i].loaded=0;

        // on ouvre le fichier
        FILE * fichier = NULL;
        fichier = fopen(filename,"r");

        if(fichier == NULL){
          perror("Error opening file"); // print error
          return(-1);
        }
        char c;
        char word[MAX_LENGTH];
        filelist[i].loaded=0;
        strcpy(word, "");
        do{
          c = (char)fgetc(fichier);
          // space       new line     null       tab
          if(c == ' ' || c == '\n' ||  c == '\0' || c =='\t' || c==',' || c=='.' || c =='(' || c == ')' || c=='?' || c=='!'){
            if(strcmp(word , "")!=0){
              remove_word(htable_ptr,word,i);
              strcpy(word, "");
            }
          }
          else
          {
            strcat(word, &c); //Keeps track of current word
          }
          //characterfunction(c);
        }while(c != EOF);
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
void
print_list(listfile_entry * filelist)
{
for (int i = 0; i<sizeof(filelist); i++){
  if(filelist[i].loaded == 1 ){
    printf("%s\n",filelist[i].filename);
  }
}

}

/**
   free file table

parameters :
   filelist   : pointer to table of files
*/
void
free_filelist(listfile_entry * filelist)
{
  free(filelist);
}

// ************************************************************************
// inner functions
// ************************************************************************

// TO BE COMPLETED
