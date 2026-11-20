#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "playlist.h"


void appendSong(Node **head, const char *title) {
      Node *append = malloc(sizeof(Node));

      if(!append) return;

      strcpy(append->title, title);
      append->next = NULL;

      Node **link = head;

      while(*link != NULL){
         link = &(*link)->next;
      }

      *link = append;
}

int removeSong(Node **head, const char *title) {


      Node **link = head;

      if(!*link) return 0;

      while(*link != NULL && strcmp((*link)->title, title) != 0){
         link = &(*link)->next;
      }
      if(!*link) return 0;

      Node *victim = *link;
      
      *link = victim->next;


      free(victim);
      
      return 1;
}

int moveUp(Node **head, const char *title) {
      


}
