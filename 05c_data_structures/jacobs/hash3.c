/*Understanding and implementing a Hash Table (in C) video
Including better hash function & other needed functions like insert, lookup and delete
NOW WE ARE DEALING WITH COLLISIONS, SOLVING THIS WITH LINEAR PROBING*/
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
//3 Any pointer that has this invalid value has been deleted
#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFFFUL) //3 To fasten lookups

typedef struct {
    char name[MAX_NAME];
    int age;
    //...add other 
} person;

// 2.Dealing with collisions we need a table of pointers
person *hash_table[TABLE_SIZE]; //use pointers to reduce space by assigning NULL 

unsigned int hash(char *name){
    // using a checksum, going through the length of the string adding values 
    int length = strnlen(name, MAX_NAME);
    unsigned int hashval = 0;
    for (int i=0; i < length; i++){
            hashval += name[i]; // not random enough
            // spread them out further by multiplying it also with the sum
            hashval =  (hashval * name[i]) % TABLE_SIZE; // % reduces it to 0 - 10 
    }
    return hashval;
}

void init_hash_table() { // to empty hash_table
    for (int i=0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

void print_table() { // print out whatever is there
    printf("Start\n");
    for (int i=0; i < TABLE_SIZE; i++) {
        if(hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else if (hash_table[i] == DELETED_NODE) {
            printf("\t%i\t---<deleted>\n",i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }    
    }
    printf("End\n");
}

bool hash_table_insert(person *p) { // returns true if insersion was successful
    if (p == NULL) return false;  
    int index = hash(p->name); 
    for (int i=0; i < TABLE_SIZE; i++){ // loop trough looking for open field
        int try = (i + index) % TABLE_SIZE; // starting at our index
        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE) { // open field
            hash_table[try] = p; // put there
            return true;
        }
    }
    return false; // If we go through entire table without finding open space
}

// Find person in table by name, returns NULL if not found & poiter if found
person *hash_table_lookup(char *name) {
    int index = hash(name); //compute hash on the name
    for (int i=0; i < TABLE_SIZE; i++) { // loop trough looking for open field
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL)  // Stop
            return false; // not found here
        if (hash_table[try] == DELETED_NODE) continue; 
        // if its not NULL or DELETED, check if the names match
        if (strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0) {
        return hash_table[try]; // name found at this location
        } 
    }
    return NULL; // name not found
}

person *hash_table_delete(char *name) {
    int index = hash(name); //compute hash on the name
    for (int i=0; i < TABLE_SIZE; i++) { // loop trough looking for open field
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL)  // Stop
            return false; // not found here
        if (hash_table[try] == DELETED_NODE) continue; 
        

        if (strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0) {
        
        person *tmp = hash_table[try];
        hash_table[try] = DELETED_NODE; // Keep on looking till you find NULL
        return tmp; // name found at this location
        }
    } 
    return NULL;

}

int main()
{
    init_hash_table();

    // make some people
    person jacob = {.name="Jacob", .age=256};
    person kate = {.name="Kate", .age=27};
    person mpho = {.name="Mpho", .age=14};
    person sarah = {.name="Sarah", .age=16};
    person edna = {.name="Edna", .age=89};
    person maren = {.name="Maren", .age=19};
    person eliza = {.name="Eliza", .age=79};
    person robert = {.name="Robert", .age=68};
    person jayne = {.name="Jayne", .age=54};
    person shaun = {.name="Shaun", .age=54};


    // add them to the hash table
    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);
    hash_table_insert(&sarah);
    hash_table_insert(&edna);
    hash_table_insert(&maren);
    hash_table_insert(&eliza);
    hash_table_insert(&robert);
    hash_table_insert(&jayne);
    hash_table_insert(&shaun);
    print_table();

    // lookup a person thats there, We get back NULL or pointer to the person
    person *tmp = hash_table_lookup("Mpho"); 
    if (tmp == NULL) { 
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }

    tmp = hash_table_lookup("George"); 
    if (tmp == NULL) { 
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }

    hash_table_delete("Mpho");
    hash_table_delete("Shaun");
    print_table();

    return 0;
}