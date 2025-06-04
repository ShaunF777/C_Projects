#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;
int main(int argc, char *argv[]) // without cs50lib, we use char * instead of string
{
    FILE *src = fopen(argv[1], "rb"); //"rb" read in binary from argv[1] from pointer src
    FILE *dst = fopen(argv[2], "wb"); //"wb" write in binary to argv[2] from pointer dst

    BYTE b; // Lets read byte-for-byte using b, our 8bit variable we created
    // &b(address of b) is where i want you to put 1 byte from the file at a time
    // sizeof(b) because next time we can make b more than 8bit, or 1byte
    // 1 how many bytes at a time = 1byte
    // src from the source's pointer location = src
    while (fread(&b, sizeof(b), 1, src) !=0) // fread tells you how many bytes we've successfuly read
    // because we are reading 1 byte at a time, fread will give you 1 or 0 eavery time
    // i.e. while fread succeeds to read bytes from the file
    {
        // Where to write to?
        // From location &b, 1byte-size, 1byte/time, write to dst
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(dst);
    fclose(src);
}
