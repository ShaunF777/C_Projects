#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Do you agree? ");

    if  (c == 'y' || c == 'Y')  //Ternary operator can be used to shorthand this
                                // (condition)          ? then expression       : else expression
                                //( c=='y' || c=='Y') ? printf("Agreed.\n")   : (c == 'n' || c == 'N') ? printf("Not agreed.\n") : ;
    {
        printf("Agreed.\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Not agreed.\n");
    }

    char d = get_char("Do you agree? ");

    (d == 'y' || d == 'Y') ? printf("Agreed.\n") : (d == 'n' || d == 'N') ? printf("Not agreed.\n") : printf("Invalid input.\n");

}