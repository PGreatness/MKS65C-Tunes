#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

node * table[27]; //table, required
char arr[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ!";
int song_count = 0; //total number of songs, may be needed

void print_list() {
  for(int i=0;i<song_count;i++){
    node *start=table[i];
    print_list(start);
  }
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
void print_letter(char artist){
  char * makeint=strchr(arr,artist);
  int index= makeint-arr+1;
  node *start = table[index];
  print_list(start);
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
   return delete_song(start,name,artist);
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
