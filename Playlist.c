/*
      Disclaimer! This program is based on a coding exercises 
      assigned by my professor. These are academic practice problems, and the 
      repository serves as a record of my own 
      learning, solutions, and progress. 
      
      Not all original code or problem ideas are mine.
*/

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
      if(*head == NULL || strcmp((*head)->title, title) == 0){
            return 0;
      }

      Node **link = head;

      while(*link != NULL && (*link)->next != NULL){
            if(strcmp((*link)->next->title, title) == 0){
                  Node *target = (*link)->next;


                  //swapping is still experimental..
                  (*link)->next = target->next;
                  target->next = *link;
                  *link = target;

                  return 1;
            }
            link = &(*link)->next;
      }

      return 0;
}
