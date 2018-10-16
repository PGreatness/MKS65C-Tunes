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
    if (prev_song) {
      prev_song->next = new_song;
    }
    new_song->next = next_song; //song is the beginning of the list
    if (next_song) {
      next_song->prev = new_song;
    }
    song_count++; //new song has been added, increase song count
    return new_song; //return this song
}

node * insert_front(node * next_song, char * name, char * artist) {
  return insert(next_song, NULL, name, artist);
}
void print_list(node * start) {
    while (start) {
        printf("[ %s ]\tby: [ %s ]\n", start->name, start->artist);
        start = start->next;
    }
}
/*node * insert_order(node * next_song, char * name, char * artist){
  node * new_song = malloc(sizeof(node)); //allocate certain number of memory for each node
  strcpy(new_song->name, name); //set the name of the song
  strcpy(new_song->artist, artist); //set the name of the artist
  if(next_song ==NULL || strcmp(artist,next_song->artist)<0){
    return insert_front(next_song,name,artist);
  }
  while(next_song!=NULL && strcmp(artist,next_song->artist)>0){
    next_song=next_song->next;
  }
  return insert(next_song,next_song->prev,name,artist);
}*/

node * order_insert(node * this_song, char * name, char * artist) {
  node * song = this_song;
  while (song->next) {
    if (strcmp(song->artist, artist) >= 0) {
      if (strcmp(song->name, name) > 0) {
        return insert(song, song->next, name, artist);
      }
    }
    song = song->next;
  }
  return insert(NULL, this_song, name, artist);
}

int main() {
node * head=NULL;
  char a[5]="fish";
  char b[9]="banana";
  char c[256]="cats";
  char d[256]="dogs";
  char e[256]="gorilla";
  char f[256]="gorillaz";
  printf("Head at NULL:\n");
  print_list(head);
  head=insert_front(head,a,b);
  head = insert_front(head, c, d);
  printf("Head now has a song called \'fish\' by \'banana\':\n");
  print_list(head);
  head=order_insert(head,e,f);
  printf("Head now has a song called \'gorilla\' by \'gorillaz\':\n");
  //head=insert_order(head,c,d);
  //head=insert_order(head,c,b);
  print_list(head);
}
