#ifndef myLinkedList_H_
#define myLinkedList_H_

typedef struct song_node {
  struct song_node * prev;
  char name[256];
  char artist[256];
  struct song_node * next;
} node;

node * insert(node * next_song, node * prev_song, char * name, char * artist);
node * insert_front(node * next_song, char * name, char * artist);
void print_list(node * start);
node * insert_order(node * this_song, char * name, char * artist);
node * search(node * start, char * name, char * artist);
node * first_song_by_artist(node *start, char * artist);
node * random_song(node * start);
node * delete_song(node * start, char * name, char * artist);
node * delete_list(node * start);
#endif