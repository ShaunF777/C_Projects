#include <stdio.h>

int main(void)
{
    char filename[9];

    int i = 4;
    for (int j = 0; j < i; j++)
    {
        sprintf(filename, "%03i.txt", j); // Just to populate the string 'filename' with the actual name
        FILE *txt = fopen(filename, "a"); // If the file existed 'filename' would be i.e. '004.txt'
        if (txt == NULL)
        {
            fclose(txt);
            return 1;
        }
        fwrite(filename, sizeof(j), 1 , txt);

    fclose(txt);
    }

}

/*
char buffer[13];

    int i = 50;
    sprintf(buffer, "This is CS%i", i);
    printf("%s\n", buffer);

    float f = 50.0;
    sprintf(buffer, "This is CS%.0f", f);
    printf("%s\n", buffer);
*/
