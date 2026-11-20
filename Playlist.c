#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "playlist.h"

/* Append a song to the END of the playlist. */
void appendSong(Node **head, const char *title) {
   /* TODO: allocate a node, copy the title, link it at the tail.
      Hint: walk with a Node ** so the empty-list case needs no special case. */
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

/* Remove the FIRST song whose title matches exactly.
   Return 1 if removed, 0 if no such song. */
int removeSong(Node **head, const char *title) {
    /* TODO: walk with a Node ** handle. When the title matches (strcmp == 0),
      unlink the node (*link = victim->next), free it, and return 1.
       Return 0 if you reach the end without a match. */

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

/* Move the song with the given title ONE position toward the front.
   If it is already first or not found, the list is unchanged.
   Return 1 if the list changed, 0 otherwise. */
int moveUp(Node **head, const char *title) {
   /* TODO: return 0 if the list is empty or the first song already matches.
       Otherwise walk with a Node **link, looking at (*link) and (*link)->next.
      When the NEXT node matches, splice it in front of the current one using
       only pointer writes (no prevLink variable needed) and return 1. */


}