#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct song_node {
  struct song_node * prev;
  char name[256];
  char artist[256];
  struct song_node * next;
} node;
node * table[27]; //table, required
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

/*
* Insert the song at the correct place in the list of songs.
*/
node * insert_order(node * this_song, char * name, char * artist) {
  node * song = this_song; //copy to iterate down and list to find the right place
  while (song->next) { //should go through until song is the last node in list
    if (strcmp(song->artist, artist) >= 0) { //curr song's artist is greater than this artist
      if (strcmp(song->name, name) > 0) { //curr song's name is greater than this name
        insert(song->next, song, name, artist); //put between song->next and curr song
        return this_song; //return head of given list
      }
    }
    song = song->next; //IFs didn't work, send the next song in
  }
  insert(NULL, song, name, artist); //all the songs didn't work, make last of the list
  return this_song; //always return head of list
}
node * search(node * start, char * name, char * artist) {
    while (start) {
        if (strcmp(start->name, name) == 0 && strcmp(start->artist, artist) == 0) {
            return start;
        }
        start = start->next;
    }
    //song not in list
    printf("Artist and name not in list");
    return NULL;
}
node * first_song_by_artist(node *start, char * artist) { 
  while(start){
    if(strcmp(start->artist,artist)==0){
      return start;
    }
    start = start ->next;
  }
      //song not in list
    printf("Artist not in list");
    return NULL;
}
node * random_song(node * start) {
    unsigned int seed = time(NULL);
    srand(seed);
    int song_number = rand() % song_count;
    int i = 0;
    for (; i < song_number; i++) {
        start = start->next;
    }
    return start;
}
node * delete_song(node * start, char * name, char * artist) {
  node * prev;
   node * removed = start;
   if(removed!=NULL && strcmp(removed->name, name) == 0 && strcmp(removed->artist, artist) == 0){
     start=removed->next;
     free(removed);
     return start;
   }
    while (removed != NULL && strcmp(removed->name, name) != 0 && strcmp(removed->artist, artist) != 0) {
        prev=removed;
        removed = removed->next;
    }
    if(removed==NULL){//song not in list
        printf("Artist and name not in list");
      return start;
    }
    prev->next = removed->next;
    free(removed);
    return start;
}
node * delete_list(node * start) {
  node * song_killer;
    while (start!=NULL) {
    song_killer=start;
	  start=start->next;
	  free(song_killer);
  }
  return start;
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
  head=insert_order(head,e,f);
  printf("Head now has a song called \'gorilla\' by \'gorillaz\':\n");
  //head=insert_order(head,c,d);
  //head=insert_order(head,c,b);
  print_list(head);
  printf("Is \'fish\' by \'banana\' in this list?\n Yes \'%s\' by \'%s\'\n",search(head, a,b)->name,search(head, a,b)->artist);
  head=insert_order(head,e,b);
  printf("What is the first song in the playlist by \'banana\'?\n The first song is \'%s\'\n",first_song_by_artist(head,b)->name);
  print_list(head);
  printf("I'm feeling adventurous. Play me any one of my songs. \n Now playing ... [%s] by %s\n",random_song(head)->name,random_song(head)->artist);
  printf("I don't really like \'fish\' by \'banana\' in this list... Imma just take it out!\n");
  head=delete_song(head,a,b);
  print_list(head);
  printf("Emptying out playlist!!!!!!!\n");
  head=delete_list(head);
  if(head ==NULL){printf("List is now empty!!!\n");}
}
