#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Do you agree? ");

    if  (c == 'y' || c == 'Y')  //Ternary operator can be used to sharthand this
                                // (condition)          ?   then expressio      :   else expression
                                //if( c=='y' || c=='Y') ? printf("Agreed.\n")   : if (c == 'n' || c == 'N') ? printf("Not agreed.\n") : ;
    {
        printf("Agreed.\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Not agreed.\n");
    }
}