#include <cs50.h>
#include <stdio.h>
//The header is a phone number you can call, while...
//...the library is the actual person you can reach there!
//It's the fundamental difference between "interface" and "implementation";
//the interface (header) tells you how to call some functionality (without knowing how it works),
//while the implementation (library) is the actual functionality.
// from https://stackoverflow.com/questions/924485/whats-the-difference-between-a-header-file-and-a-library

int main(void)
{
    string answer = get_string("What's your name? "); //get_string saves the return value(your answer) into the string variable called answer
    printf("hello, %s\n", answer); //You get many placeholders or format code for printf like, %c, %f, %i, %li
}

