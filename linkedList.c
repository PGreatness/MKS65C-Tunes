#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//construct a struct called song_node and define it as "node"
typedef struct song_node { 
    char name[100];
    char artist[100];
    struct song_node *next;
} node;
struct node * table[27]; //table, required
int song_count = 0; //total number of songs, may be needed

node * insert_front(node * song, char * name, char * artist) {
    node * new_song = malloc(sizeof(node)); //allocate certain number of memory for each node
    strcpy(new_song->name, name); //set the name of the song
    strcpy(new_song->artist, artist); //set the name of the artist
    new_song->next = song; //song is the beginning of the list
    song_count++; //new song has been added, increase song count
    return new_song; //return this song
}

node * insert_order(char * name, char * artist) {
    node * new_song = malloc(sizeof(node)); //allocate certain number of memory for each node
    strcpy(new_song->name, name); //set the name of the song
    strcpy(new_song->artist, artist); //set the name of the artist
    //rest to be implemented
    song_count++;
}

void print_list(node * start) {
    while (start) {
        printf("[ %s ]\tby: [ %s ]", start->name, start->artist);
        start = start->next;
    }
}

node * search(node * start, char name, char artist) {
    while (start) {
        if (strcmp(start->name, name) == 0 && strcmp(start->artist, artist) == 0) {
            return start;
        }
        start = start->next;
    }
    //song not in list
    return "Artist and name not in list";
}

node * first_song_by_artist(char artist) { /*to be implemented */}

//will not work until table is populated
node * random_song() {
    unsigned int seed = time(NULL);
    srand(seed);
    int song_number = rand() % song_count;
    int i = 0;
    node * selected_song = table[0];
    int table_row = 0;
    for (; i < song_number; i++) {
        if (selected_song = NULL) {
            selected_song = table[++table_row];
        }
        selected_song = selected_song->next;
    }
    return selected_song;
}

node * delete_song(node * killed_song) {
    //will be implemented after ordered list is done
}

//will not work until table is populated
node * delete_list() {
    node * song_killer = table[0];
    int table_row = 0;
    int i = 0;
    for (; i < song_count; i++) {
        if (song_killer = NULL) {
            song_killer = table[++table_row];
        }
        node * this_song = song_killer;
        song_killer = song_killer->next;
        free(this_song);
        this_song = NULL;
    }
    return song_killer;
}


void main() {

}