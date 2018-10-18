#ifndef myMusicLibrary_H_
#define myMusicLibrary_H_

typedef struct song_node {
  struct song_node * prev;
  char name[256];
  char artist[256];
  struct song_node * next;
} node;

node * insert(node * next_song, node * prev_song, char * name, char * artist);
node * insert_front(node * next_song, char * name, char * artist);
void print_list();
node * insert_order(node * this_song, char * name, char * artist);
node * search(char * name, char * artist);
void song_by_artist(char * artist);
node * shuffle();
node * delete_song(char * name, char * artist);
node * delete_list();
node * insert_into_table(char * name, char * artist);
void print_letter(char artist);
#endif

