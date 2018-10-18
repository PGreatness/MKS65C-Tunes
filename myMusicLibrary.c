#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

node * table[27]; //table, required
char arr[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ!";
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
  for(int i=0;i<song_count;i++){
    node *start=table[i];
    while (start) {
        printf("[ %s ]\tby: [ %s ]\n", start->name, start->artist);
        start = start->next;
    }
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
node * insert_into_table(char * name, char* artist){//might not work
  char * makeint = strchr(arr,artist[0]);
  int index=makeint-arr+1
  node * start=table[index];
  return insert_order(start,name,artist);
}
/*
* Searches for song with designated name and artist.
*/
node * search( char * name, char * artist) {
char * makeint=strchr(arr,artist[0]);
  int index= makeint-arr+1;
  node *start = table[index];
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
/*
* Searches for songs with artist.
*/
void song_by_artist(char * artist) { 
  char * makeint=strchr(arr,artist[0]);
  int index= makeint-arr+1;
  node *start = table[index];
  while(start){
    if(strcmp(start->artist,artist)==0){
      printf("[%s] by %s\n", start->name, start->artist);
    }
    start = start ->next;
  }
}
/*
* Randomly chooses and prints song from list.
*/
node * shuffle() {
    unsigned int seed = time(NULL);
    srand(seed);
    for(int i = 0; i< 5 ; i++){
    int random = rand() %27;
    int song_number = rand() % song_count;
    int i = 0;
    node * start = table[random];
    for (; i < song_number; i++) {
        start = start->next;
    }
    printf("Now playing [%s] by [%s]\n",start->name, start->artist);
    }
}
/*
* Removes song with designated name and artist.
*/
node * delete_song(char * name, char * artist) {
   char * makeint = strchr(arr,artist[0]);
   int index=makeint-arr+1
  node * start=table[index];
  node * first = start;
   node * removed=search(start,name,artist);
   node * prev_song=removed->prev;
   if(first!=NULL && strcmp(first->name, name) == 0 && strcmp(first->artist, artist) == 0){//shifts head down if head is to be removed
     start=first->next;
     free(first);
     return start;
   }
    if(removed==NULL){//song not in list
        printf("Artist and name not in list");
      return start;
    }
    prev_song->next = removed->next;
    free(removed);
    return start;
}
/*
* Deletes the entire playlist.
*/
node * delete_list() {
  node* start;
  for(int i=0;i<song_count;i++){
    start= table[i];
    node * song_killer;
    while (start!=NULL) {
    song_killer=start;
	  start=start->next;
	  free(song_killer);
    }
  }
  return start;
}