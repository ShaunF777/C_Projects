/*Understanding and implementing a Hash Table (in C) video
Including better hash function & other needed functions like insert, lookup and delete
@21MINUTES - NOW WE ARE DEALING WITH COLLISIONS, SOLVING THIS LINKED LISTS aka external chaining*/
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 59
// No more deletion markers, cos were prepending 

typedef struct person { //4 stating the struct name crucial
    char name[MAX_NAME];
    int age;
    //...add other stuff
    struct person *next; // 4 because we're adding a next pointer inside
} person;

// 2.Dealing with collisions we need a table of pointers
person *hash_table[TABLE_SIZE]; //use pointers to reduce space by assigning NULL 

unsigned int hash(char *name){
    // using a checksum, going through the length of the string adding values 
    int length = strnlen(name, MAX_NAME);
    unsigned int hashval = 0;
    for (int i=0; i < length; i++){
            hashval += name[i]+3141592653589; // not random enough
            // spread them out further by multiplying it also with the sum
            hashval =  (hashval * name[i]) % TABLE_SIZE; // % keeps 0 - TABLE-SIZE 
    }
    return hashval;
}

void init_hash_table();

void print_table();

bool hash_table_insert(person *p);

// 4 not through table anymore, but through the list thats at index
person *hash_table_lookup(char *name);

person *hash_table_delete(char *name);

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
        printf("Lookup came back with %s!\n", tmp->name);
    } else {
        printf("Found %s.\n", tmp->name);
    }

    tmp = hash_table_lookup("George"); 
    if (tmp == NULL) { 
        printf("Lookup came back with %s!\n", tmp->name);
    } else {
        printf("Found %s.\n", tmp->name);
    }

    person *deleted_person = hash_table_delete("Mpho");
    printf("Deleted person is: %s\n", deleted_person->name);
    //hash_table_delete("Shaun");
    print_table();

    return 0;
}

void init_hash_table() { // to empty hash_table
    for (int i=0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

void print_table() { // print out whatever is there
    printf("Start\n");
    for (int i=0; i < TABLE_SIZE; i++) {//4 Iterate through array of person lists
        if(hash_table[i] == NULL) {//4 If there's nothing there
            printf("\t%i\t---\n", i);//4 Print just the index number and ---
        } else {
            printf("\t%i\t",i); //4 TAB Print index number TAB 
            person *trav = hash_table[i];//4 To traverse over list
            while (trav != NULL) { //4 Till we reach the last person
                printf("%s - ", trav->name); //4 Print out this current person
                trav = trav->next; //4 Point to next person down the list
            
            }
            printf("\n");
        }    
    }
    printf("End\n");
}

bool hash_table_insert(person *p) { // Returns true if insersion was successful
    if (p == NULL) return false; // 4 Don't have to hunt for open spots anymore
    int index = hash(p->name); //4 Get the index number via hash
    // If hash_table[index] is still NULL, then thats what the 1st node will get
    p->next = hash_table[index]; //4 New person must 1st point to current person thats at index 
    hash_table[index] = p; //4 Add new person to the hashed index, THIS MOVES THE LIST(PERSONS) BACK  
    return true; //4 Basically just hash the new name and put in front at index
}

// 4 Look through the list thats at index, specifically if more than one node exists
person *hash_table_lookup(char *name) {// 4 Don't have to hunt for open index's anymore
    int index = hash(name); //4 Compute index. WE ONLY NEED THIS ONE LIST 
    person *trav = hash_table[index]; // 4 Assign traverse pointer to head of the list at index
    while(trav != NULL && //4 While there is data in the list AND
    strncmp(trav->name, name, MAX_NAME) !=0) {//4 Argument(name) does not match trav->name
        trav = trav->next; //4 Go through list looking for match
    }
    return trav;//4 Person found or NULL ie. at the end of this list, no match found 
}

/*NOTE: working on the stack, does not require freeing list nodes*/
person *hash_table_delete(char *name) { 
    int index = hash(name);
    person *trav = hash_table[index]; // Initialize trav: Start at the head of the list
    person *prev = NULL; // Initialize prev to NULL
    // The while loop traverses the linked list to find the node with the matching name.
    while(trav != NULL && strncmp(trav->name, name, MAX_NAME) !=0) {
    // 1st iteration: If trav->name does not match name, move prev to trav and trav to trav->next.
        prev = trav; 
        trav = trav->next;
    /*Subsequent Iterations: trav moves to the next node. prev moves to the node trav was previously pointing to.
    This continues until trav is NULL (end of the list) or trav->name matches name.*/
    }
    if (trav == NULL) return NULL;// Empty node
    // Deleting the Head Node: If prev is NULL, it means trav is the head of the list. 
    if (prev == NULL) hash_table[index] = trav->next;// We update the head of the list to trav->next.
    /*Before: hash_table[index] -> [Node1] -> [Node2] -> [Node3] -> NULL
    After:  hash_table[index] -> [Node2] -> [Node3] -> NULL*/

    // Deleting a Middle or Last Node:
    else prev->next = trav->next; //If prev is not NULL, it means trav is not the head. 
    /*Before: [Node1] -> [Node2] -> [Node3] -> NULL
    After:  [Node1] -> [Node3] -> NULL*/
    /*We update the address inside prev->next to trav->next, effectively bypassing the node to be deleted.
    In both cases, the node (trav) is effectively removed from the list, and the list remains properly linked.*/
    return trav;
}
/*Why the prev Pointer is Needed: 
The prev pointer is essential for maintaining the integrity of the linked list when deleting a node. 
1stly Deleting the Head Node: If the node to be deleted is the first node (head) of the list, 
prev will be NULL. In this case, we update the head of the list directly.

2ndly Deleting a Middle or Last Node: If the node to be deleted is not the head, 
prev will point to the node just before the one to be deleted. 
This allows us to bypass the node to be deleted by updating the next pointer of the prev node.*/

/*Summary
The prev pointer is crucial for correctly updating the linked list when deleting a node.
The while loop traverses the list, updating prev and trav until the node to be deleted is found or the end of the list is reached.
Depending on whether the node to be deleted is the head or not, the list is updated accordingly.*/