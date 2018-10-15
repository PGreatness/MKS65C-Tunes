#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct song_node {
  struct song_node * prev;
  char name[256];
  char artist[256];
  struct song_node * next;
} node;
struct node * table[27]; //table, required
int song_count = 0; //total number of songs, may be needed

node * insert(node * next_song, node * prev_song, char * name, char * artist) {
    node * new_song = malloc(sizeof(node)); //allocate certain number of memory for each node
    strcpy(new_song->name, name); //set the name of the song
    strcpy(new_song->artist, artist); //set the name of the artist
    new_song->prev = prev_song;
    new_song->next = next_song; //song is the beginning of the list
    song_count++; //new song has been added, increase song count
    return new_song; //return this song
}

node * insert_front(node * next_song, char * name, char * artist) {
  return insert(next_song, NULL, name, artist);
}



int main() {

}
