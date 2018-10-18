#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "myMusicLibrary.h"

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
  printf("Is \'fish\' by \'banana\' in this list?\n Yes \'%s\' by \'%s\'\n",search(a,b)->name,search(a,b)->artist);
  head=insert_order(head,e,b);
  printf("Find me songs by \'banana\'\n Finding songs....\n");
  //song_by_artist(head,b);
  print_list(head);
  printf("I'm feeling adventurous. Play me any one of my songs. \n Now playing ... [%s] by %s\n",random_song(head)->name,random_song(head)->artist);
  printf("I don't really like \'fish\' by \'banana\' in this list... Imma just take it out!\n");
  head=delete_song(head,a,b);
  print_list(head);
  printf("Emptying out playlist!!!!!!!\n");
  head=delete_list(head);
  if(head ==NULL){printf("List is now empty!!!\n");}
}
