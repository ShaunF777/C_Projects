/*This program is not compiling - The problem is that the variables x and y are declared inside the main function, so they are 
not visible inside the add function. In C, variables have block scope, so add cannot access x and y from main.*/
#include <cs50.h>
#include <stdio.h>

int add(void);// copy of prototype declared
int main(void)
{
    int x = get_int("x: "); //Problem
    int y = get_int("y: "); // x & y is only usable inside these curly braces, inside this scope

    int z = add();      //in stead of x + y we are outsourcing the function and putting its anwer inside z
    printf("%i\n", z);  //print the value of an integer placeholder, 
    // use arithmatic opperators available for calculations(+,-,*,/,%)(% is modulus & gives the remainder of devision)
}
// make reusable add function
int add(void)//this function has an int return value
{
    return x + y;
}
