/* This is an interactive demonstration of C fundamentals, demonstrating the use of:
- arithmetic & logic 
- conditionals 
- switch
- loops
- string comparison
It prints each code line with a comment.
Then asks the user for input where appropriate.
Then shows the result and explains it.
*/
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Helper function to print code and comment, then wait for user
void explain(const char *code, const char *comment)
{
    printf("\nCODE:    %s\n", code);
    printf("COMMENT: %s\n", comment);
    printf("Press Enter to continue...\n");
    getchar();
}

int main(void)
{
    printf("Welcome to the C Fundamentals Interactive Demo!\n");
    printf("This program will guide you through basic C concepts.\n\n");
    // 1. Arithmetic Operators
    printf("Lests begin with 1. Arithmetic Operators");
    explain("int x, y;", "Declare x and y variables of type integer.");
    int x = get_int("Enter a value for x: ");
    int y = get_int("Enter a value for y: ");

    explain("x *= 5;", "Multiply x by 5 (x = x * 5).");
    x *= 5;
    printf("Result: x is now %i\n", x);

    explain("y /= 3;", "Divide y by 3 (y = y / 3).");

    y /= 3;
    printf("Result: y is now %i\n", y);

    explain("x++;", "Increase x by 1 (x = x + 1).");
    x++;
    printf("Result: x is now %i\n", x);

    explain("y--;", "Decrease y by 1 (y = y - 1).");
    y--;
    printf("Result: y is now %i\n", y);

    explain("int a = 13 %% 4;", "Modulo gives the remainder of dividing 13 by 4 (13 %% 4 = 1).");
    int a = 13 % 4;
    printf("Result: a = %i\n", a);

    explain("int b = 12345678 %% 10;", "Modulo 10 pushes back the comma, giving the last digit.");
    int b = 12345678 % 10;
    printf("Result: b = %i\n", b);

    printf("use %% 20 on any integer, the result will always be one of the 20 values: 0, 1, 2, ..., 19.\n");
    printf("This is why %% 20 is often used to wrap numbers into a range of 0 to 19, which can look random if the input is unpredictable.");
    explain("int c = 12345678 % 20;", "Modulo 20 gives a value from 0 to 19.");
    int c = 12345678 % 20;
    printf("Result: c = %i\n", c);

    printf("Remember that C uses integer division, so 5 / 2 = 2, not 2.5.\n");
    printf("To get a decimal result, you need to use floating-point numbers (e.g., 5.0 / 2.0).\n");
    printf("For example, 5.0 / 2.0 = 2.5.\n");
    printf("Also, remember that C does not have a built-in decimal type, so you need to use float or double for decimal numbers.\n");
    printf("For example, 5.0f / 2.0f = 2.5f.\n");
    explain("int d = (12345678 % 100) / 10;", "Modulo 100 gives last two digits, then divide by 10 to get the tens digit.");
    int d = (12345678 % 100) / 10;
    printf("Result: d = %i\n", d);

    // 2. Logical and Relational Operators
    printf("2. Logical and Relational Operators\n");
    explain("Relational operators: <, >, <=, >=, ==, !=", "Compare two values and return true or false.");
    explain("Logical operators: || (OR), && (AND), ! (NOT)", "Combine or invert boolean expressions.");
    bool logic = (x > 10 && y < 10) || !(a == 1);
    printf("Remember the end results of x, y and a?\n");
    printf("Example: (x > 10 && y < 10) || !(a == 1) evaluates to %s\n"
           " (x > 10 is %s, y < 10 is %s, a == 1 is %s)\n",
           logic ? "true" : "false",
           (x > 10) ? "true" : "false",
           (y < 10) ? "true" : "false",
           (a == 1) ? "true" : "false");

    // 3. Conditional Statements
    printf("3. Conditional Statements\n");
    explain("if (x < y) { ... }", "If statement checks a condition and executes code if true.");
    if (x < y)
    {
        printf("x (%i) is less than y (%i)\n", x, y);
    }
    else
    {
        printf("x (%i) is not less than y (%i)\n", x, y);
    }
    explain("if (x == y) { ... }", "If statement checks if x equals y.");
    if (x == y)
    {
        printf("x (%i) is equal to y (%i)\n", x, y);
    }
    else
    {
        printf("x (%i) is not equal to y (%i)\n", x, y);
    }
    explain("if (x != y) { ... }", "If statement checks if x is not equal to y.");
    if (x != y)
    {
        printf("x (%i) is not equal to y (%i)\n", x, y);
    }
    else
    {
        printf("x (%i) is equal to y (%i)\n", x, y);
    }
    explain("if (x <= y) { ... }", "If statement checks if x is less than or equal to y.");
    if (x <= y)
    {
        printf("x (%i) is less than or equal to y (%i)\n", x, y);
    }
    else
    {
        printf("x (%i) is greater than y (%i)\n", x, y);
    }
    explain("if (x >= y) { ... }", "If statement checks if x is greater than or equal to y.");
    if (x >= y)
    {
        printf("x (%i) is greater than or equal to y (%i)\n", x, y);
    }
    else
    {
        printf("x (%i) is less than y (%i)\n", x, y);
    }
    explain("if (x < y) { ... } else if (x == y) { ... } else { ... }", "If-else if-else checks multiple conditions.");
    if (x < y)
    {
        printf("x (%i) is less than y (%i)\n", x, y);
    }
    else if (x == y)
    {
        printf("x (%i) is equal to y (%i)\n", x, y);
    }
    else
    {
        printf("x (%i) is greater than y (%i)\n", x, y);
    }
    explain("if (x > y) { ... } else { ... }", "If-else chooses between two branches.");
    if (x > y)
    {
        printf("x (%i) is greater than y (%i)\n", x, y);
    }
    else
    {
        printf("x (%i) is not greater than y (%i)\n", x, y);
    }
    // Ternary operator
    printf("The ternary operators reduces conditional code size: (condition) ? value_if_true : value_if_false\n");
    explain("int z = (x > y) ? x : y;", "Ternary operator: assigns the greater of x or y to z.");
    int z = (x > y) ? x : y;
    printf("Result: z = %i\n", z);

    // 4. Switch Statement
    printf("4. Switch Statement\n");
    explain("switch(r) { case ... }", "Switch checks a variable against multiple cases, executing the matching case.");
    explain("get_int(\"Enter a number (1-3): \")", "Gets an integer input from the user.");
    explain("case 1: ... break;", "Each case executes code until a break statement is reached.");
    explain("default: ...", "Default case executes if no other case matches.");
    int r = get_int("Enter a number (1-3): ");
    switch (r)
    {
        case 1: printf("One!\n"); break;
        case 2: printf("Two!\n"); break;
        case 3: printf("Three!\n"); break;
        default: printf("Sorry!\n");
    }

    // 5. Loops
    printf("5. Loops\n");
    explain("for (int i = 0; i < 5; i++) { ... }", "For loop repeats a set number of times.");
    for (int i = 0; i < 5; i++)
    {
        printf("Iteration %i\n", i + 1);
    }
    explain("while (i < n) { ... }", "While loop repeats as long as condition is true.");
    int n = get_int("Enter a positive number for loop count: ");
    int i = 0;
    while (i < n)
    {
        printf("Iteration %i\n", i + 1);
        i++;
    }

    explain("do { ... } while (condition);", 
    "Do-while loops are used when you want the code inside the loop to run at least once, even if the condition is false initially.\n"
    "This is useful for input validation, menus, or any action that must happen before checking a condition.\n");

    printf("For example, here we use a do-while loop to keep asking for a number until you enter one greater than 5.\n");
    int m;
    do
    {
        m = get_int("Enter a number greater than 5: ");
    }
    while (m <= 5);
    printf("You entered %i, which is greater than 5.\n", m);


    // 6. String functions (from string.h)
    printf("6. String Functions(from string.h)\n");
    explain("#include <string.h>", "Allows use of string manipulation functions.");
    explain("strlen(s)", "Returns the length of a string.");
    string s = get_string("Enter a string: ");
    printf("The length of \"%s\" is %zu characters.\n", s, strlen(s));
    explain("string s1 = get_string()", "Gets a string input from the user, and stores it in s1.");
    explain("strcmp(s1, s2)", "Compares two strings and returns 0 if they are equal.");
    string s1 = get_string("We will compare 2 words. Enter a word: ");
    string s2 = get_string("Enter another word: ");
    printf("Comparing \"%s\" and \"%s\"...\n", s1, s2);
    if (strcmp(s1, s2) == 0)
        printf("The words are the same!\n");
    else
        printf("The words are different.\n");

    printf("\nEnd of interactive fundamentals demo!\n");
    return 0;
}