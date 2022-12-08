#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "functions.h"

//------------------------------------------------------------------------

int
main()
{
  // create hash table
  hash_table * table = create_table();

  // create filelist array
  listfile_entry * list_file = create_filelist(MAX_FILES);

  // display menu
  while (1) {
    int nbchoices = 0;
    fprintf(stderr, "\nChoisir une action\n");
    fprintf(stderr, "%d. Load a file in dictionary\n", ++nbchoices);
    fprintf(stderr, "%d. Search a word in dictionary\n", ++nbchoices);
    fprintf(stderr, "%d. Remove file from dictionary\n", ++nbchoices);
    fprintf(stderr, "\n");
    fprintf(stderr, "%d. Print dictionary\n", ++nbchoices);
    fprintf(stderr, "%d. Print file list\n", ++nbchoices);
    fprintf(stderr, "\n0. Quit\n");
    int choice;
    char file[MAX_LENGTH];
    char word[MAX_LENGTH];
    while (1) {
      strcpy(word,"");
      fprintf(stderr, "Your choice ? ");
      scanf("%d", & choice);
      if (choice >= 0 && choice <= nbchoices) { break; }
      fprintf(stderr, "\nError %d is an incorrect choice\n", choice);
    }
    if (choice == 0) { break; }

    fprintf(stderr, "-------------------------------------------------\n");

    // TO BE COMPLETED

    switch (choice) {


    case 1:

      printf("Choose a file : \n");
      scanf("%s", file);
      add_file(file,list_file,table);

      break;

      // Search a word in dictionary
    case 2:
      printf("Choose a word : \n");
      scanf("%s", word);
      search_word(word, list_file, table);
      break;

      // Remove file from dictionary
    case 3:
      printf("Choose a file : \n");
      scanf("%s", file);
      remove_file(file,list_file,table);
      break;

      // Print dictionary
    case 4:
      print_table(table,list_file);
      break;

      // Print file list
    case 5:
      print_list(list_file);
      break;
    }
    fprintf(stderr, "-------------------------------------------------\n");

  }

  // the end : free allocated memory
free_table(table);
free_filelist(list_file);
  return 0;
}

// compute hash value for word
// returns : N ; 0 <= N < size
int
hashcode(char word[], int size)
{
  //printf("%s \n", word);
  if(size == 0 ){
    printf("taille max null");
    return -1;
  }
  else{
    //printf("on code le mot %s\n", word);
    int hc = 0;
    for (int i = 0; i< strlen(word); i++){
      // vérifie que le caractère est aphanumérique
      if(word[i]>=33 && word[i]<=126){
        //printf("%c de valeur %d \n", (char)word[i], word[i] );
        hc += word[i];
      }
    }
    hc = hc%size;
    return hc;
  }
}
