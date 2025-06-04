#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define BYTESIZE 512 // Find BYTESIZE and replace with 512

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open %s\n", argv[1]);
        return 1;
    }
    // Create a buffer for a block of data
    uint8_t buffer[BYTESIZE];
    char filename[9];

    int n = 0, counter = 0;
    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512) // Read 512 bytes into the buffer
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0) // If its the start of a new jpeg
        {
            counter++; // If its the 1st jpeg
            sprintf(filename, "%03i.jpg", n);
            FILE *img = fopen(filename, "w");
            fwrite(buffer, 1, BYTESIZE, img);
            n++; // To change file name of next jpeg
            fclose(img);
        }
        else if (counter > 0)
        { // If already found JPEG, keep writing the next 512 block etc.
            FILE *img = fopen(filename, "a");
            fwrite(buffer, 1, BYTESIZE, img);
            fclose(img);
        }
    }
    // close remaining open files
    fclose(card);
}
