/*Understanding and implementing a Hash Table (in C) video*/
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

int main()
{
    printf("Jacob => %u\n",hash("Jacob"));
    printf("Natalie => %u\n",hash("Natalie"));
    printf("Sarah => %u\n",hash("Sarah"));
    printf("Mpho => %u\n",hash("Mpho"));
    printf("Tebogo => %u\n",hash("Tebogo"));
    printf("Ron => %u\n",hash("Ron"));
    printf("Jane => %u\n",hash("Jane"));
    printf("Maren => %u\n",hash("Maren"));
    printf("Bill => %u\n",hash("Bill"));

    return 0;
}