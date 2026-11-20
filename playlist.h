#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <stddef.h>

typedef struct Node {
    char title[64];
    struct Node *next;
} Node;

/* Append a song to the END of the playlist. */
void appendSong(Node **head, const char *title);

/* Remove the FIRST song whose title matches exactly.
   Return 1 if removed, 0 if no such song. */
int removeSong(Node **head, const char *title);

/* Move the song with the given title ONE position toward the front.
    If it is already first or not found, the list is unchanged.
   Return 1 if the list changed, 0 otherwise. */
int moveUp(Node **head, const char *title);

#endif