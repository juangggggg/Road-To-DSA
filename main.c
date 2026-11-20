#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "playlist.h"

#define MAX_SONGS 16
#define TITLE_LEN 64

static void printPlaylist(Node *head) {
    Node *cur = head;
    while (cur != NULL) {
        printf("  - %s\n", cur->title);
        cur = cur->next;
    }
}

static void freePlaylist(Node **head) {
    Node *cur = *head;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    *head = NULL;
}

int main(void) {
    Node *head = NULL;
    int count = 0;

    printf("Enter number of songs: ");
    if (scanf("%d", &count) != 1) {
        printf("Invalid input.\n");
        return 0;
    }
    if (count < 0) count = 0;
    if (count > MAX_SONGS) count = MAX_SONGS;

    for (int i = 0; i < count; i++) {
        char title[TITLE_LEN];
        printf("Enter song %d: ", i + 1);
        if (scanf("%63s", title) != 1) {
            printf("Invalid input.\n");
            freePlaylist(&head);
            return 0;
        }
        appendSong(&head, title);
    }

    printf("Playlist:\n");
    printPlaylist(head);

    char target[TITLE_LEN];
    printf("Enter song title to remove: ");
    scanf("%63s", target);
    if (removeSong(&head, target)) {
        printf("Removed: %s\n", target);
    } else {
        printf("Not found: %s\n", target);
    }
    printf("Playlist:\n");
    printPlaylist(head);

    printf("Enter song title to move up: ");
    scanf("%63s", target);
    if (moveUp(&head, target)) {
        printf("Moved up: %s\n", target);
    } else {
        printf("No move: %s\n", target);
    }
    printf("Playlist:\n");
    printPlaylist(head);

    freePlaylist(&head);
    return 0;
}