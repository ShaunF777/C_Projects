/*Understanding and implementing a Hash Table (in C) video
Including better hash function & other needed functions like insert, lookup and delete
NOT YET DEASLING WITH COLLISIONS*/
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME];
    int age;
    //...add other 
} person;

// 2.Dealing with collisions we need a table of pointers
person *hash_table[TABLE_SIZE]; //use pointers to reduce space by assigning NULL 

unsigned int hash(const char *name){
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
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }    
    }
    printf("End\n");
}

bool hash_table_insert(person *p) { // returns true if insersion was successful
    if (p == NULL) return false; // prevent calling the function with NULL pointer 
    int index = hash(p->name); // compute the hash table index for the persons name
    if (hash_table[index] != NULL) { //check to see if there is already a person at index
        return false; // Collision
    }
    hash_table[index] = p; // if it is available, insert the person there
    return true;
}

// Find person in table by name, returns NULL if not found & poiter if found
person *hash_table_lookup(char *name) {
    int index = hash(name); //compute hash on the name
    if (hash_table[index] != NULL && // if there is a name and it matches
    strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0) {
        return hash_table[index]; // name found at this location
    } else {
        return NULL; // name not found
    }
}

person *hash_table_delete(char *name) {
    int index = hash(name); //compute hash index for the name
    if (hash_table[index] != NULL && // if there is a name and it matches name
    strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0) {
        person *tmp = hash_table[index]; //tmp will point there
        hash_table[index] = NULL; // to delete whats there
        return tmp; // pointer to deleted field
    } else {
        return NULL; // name not found
    }

}

int main()
{
    init_hash_table();

    // make some people
    person jacob = {.name="Jacob", .age=256};
    person kate = {.name="Kate", .age=27};
    person mpho = {.name="Mpho", .age=14};


    // add them to the hash table
    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);
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
    print_table();

    /*printf("Jacob => %u\n",hash("Jacob"));
    printf("Natalie => %u\n",hash("Natalie"));
    printf("Sarah => %u\n",hash("Sarah"));
    printf("Mpho => %u\n",hash("Mpho"));
    printf("Tebogo => %u\n",hash("Tebogo"));
    printf("Ron => %u\n",hash("Ron"));
    printf("Jane => %u\n",hash("Jane"));
    printf("Maren => %u\n",hash("Maren"));
    printf("Bill => %u\n",hash("Bill"));*/

    return 0;
}