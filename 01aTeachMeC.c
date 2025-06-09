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

int add(int a, int b)
{
    return a + b;
}

void print_separator(void)
{
    printf("\n---------------------------------------------\n");
}

int main(void)
{
    print_separator();
    printf("Welcome to the Interactive C Fundamentals Demo!\n");
    printf("This program will guide you through basic C concepts with code, comments, and interactive input.\n");
    print_separator();

    // 1. Input/Output and Variables
    explain("#include <cs50.h>\n#include <stdio.h>", "Include headers for input/output and CS50 functions like get_string and get_int.");
    explain("#include <stdio.h>", "Headers are shortcuts for other .c file libraries. These libraries provide abstracted functions we need localy.");

    explain("string answer = get_string(\"What's your name? \");", "Prompt the user for their name and store it as a string.");
    string answer = get_string("What's your name? ");
    printf("Hello, %s! Let's get started. It's best to follow the .c code while doing the exercise.\n", answer);

    // 2. Arithmetic Operators
    print_separator();
    printf("2. Arithmetic Operators\n");
    explain("int x = get_int(\"x: \");\nint y = get_int(\"y: \");", "Prompt the user for two integers.");
    int x = get_int("x: ");
    int y = get_int("y: ");

    explain("printf(\"%i\\n\", x + y);", "Print the sum of x and y.");
    printf("Sum: %i + %i = %i\n", x, y, x + y);

    explain("printf(\"%i\\n\", x - y);", "Print the difference of x and y.");
    printf("Difference: %i - %i = %i\n", x, y, x - y);

    explain("printf(\"%i\\n\", x * y);", "Print the product of x and y.");
    printf("Product: %i * %i = %i\n", x, y, x * y);

    explain("printf(\"%i\\n\", x / y);", "Print the integer division of x by y.");
    if (y != 0)
        printf("Integer division: %i / %i = %i In C, deviding integers will trunc all decimals.\n", x, y, x / y);
    else
        printf("Cannot divide by zero!\n");

    explain("printf(\"%i\\n\", x %% y);", "Print the remainder of x divided by y (modulo).");
    if (y != 0)
        printf("Modulo: %i %% %i = %i\n", x, y, x % y);
    else
        printf("Cannot modulo by zero!\n");

    // 3. Typecasting for Floating Point Division
    print_separator();
    printf("3. Typecasting for Floating Point Division\n");
    explain("float z = (float)x / (float)y;", "Convert x and y to float for decimal division.");
    if (y != 0)
        printf("Floating point division: %.2f / %.2f = %.5f\n", (float)x, (float)y, (float)x / (float)y);
    else
        printf("Cannot divide by zero!\n");

    // 4. Conditionals
    print_separator();
    printf("4. Conditionals\n");
    explain("if (x < y) ... else if (x > y) ... else ...", "Compare x and y and print the relationship.");
    printf("IF the condition(x < y) is true, THEN execute the following code, ELSE execute the following alternative code.\n");
    if (x < y)
        printf("%i is less than %i\n", x, y);
    else if (x > y)
        printf("%i is greater than %i\n", x, y);
    else
        printf("%i is equal to %i\n", x, y);

    explain("if (x == y) ...", "Checks if x equals y.");
    if (x == y)
        printf("%i equals %i\n", x, y);
    else
        printf("%i does not equal %i\n", x, y);

    explain("if (x != y) ...", "Checks if x is not equal to y.");
    if (x != y)
        printf("%i is not equal to %i\n", x, y);
    else
        printf("%i is equal to %i\n", x, y);

    // 5. Logical Operators
    print_separator();
    printf("5. Logical Operators\n");
    explain("if (x > 0 && y > 0) ...", "&& means AND. Checks if both x and(&&) y are positive.");
    prinf("Remember that C uses logical operators to combine conditions into one single condition.\n");
    if (x > 0 && y > 0)
        printf("Both x (%i) and y (%i) are positive.\n", x, y);
    else
        printf("At least one of x (%i) or y (%i) is not positive.\n", x, y);

    explain("if (x > 0 || y > 0) ...", "|| means OR. Checks if at least one of x or(||) y is positive.");
    printf("If either x or y is positive, the condition will be true.\n");
    if (x > 0 || y > 0)
        printf("At least one of x (%i) or y (%i) is positive.\n", x, y);
    else
        printf("Neither x (%i) nor y (%i) is positive.\n", x, y);
    explain("if (!(x < y)) ...", "! means NOT. Inverts the condition.");
    if (!(x < y))
        printf("x (%i) is not less than y (%i).\n", x, y);
    else
        printf("x (%i) is less than y (%i).\n", x, y);
    explain("if (x >= y) ...", "Checks if x is greater than or equal to y.");
    if (x >= y)
        printf("x (%i) is greater than or equal to y (%i).\n", x, y);
    else
        printf("x (%i) is less than y (%i).\n", x, y);
    explain("if (x <= y) ...", "Checks if x is less than or equal to y.");
    if (x <= y)
        printf("x (%i) is less than or equal to y (%i).\n", x, y);
    else
        printf("x (%i) is greater than y (%i).\n", x, y);
    explain("if (x == y) ...", "Checks if x is equal to y.");
    if (x == y)
        printf("x (%i) is equal to y (%i).\n", x, y);
    else
        printf("x (%i) is not equal to y (%i).\n", x, y);
    explain("if (x != y) ...", "Checks if x is not equal to y.");
    if (x != y)
        printf("x (%i) is not equal to y (%i).\n", x, y);
    else
        printf("x (%i) is equal to y (%i).\n", x, y);
    explain("if (x < y) ... else if (x == y) ... else ...", "Checks multiple conditions in sequence.");
    if (x < y)
    {
        printf("x (%i) is less than y (%i).\n", x, y);
    }
    else if (x == y)
    {
        printf("x (%i) is equal to y (%i).\n", x, y);
    }
    else
    {
        printf("x (%i) is greater than y (%i).\n", x, y);
    }

    // 9. Functions
    print_separator();
    printf("9. Functions\n");
    explain("int main(void)", "\"int\" Means it will return an integer value. \"main\"Is the primary function of program. "
           "\"(void)\" Means no initial arguments are passed into the function.\n");
    printf("The \"main\" function is where the program starts executing.\n");
    explain("In any function \"return 0;\"", "Indicates successful program termination.");
    printf("Returning 0 from main indicates that the program completed successfully.\n");
    explain("int add(int a, int b) { return a + b; }", "Defines a function to add two integers.");
    int a = get_int("Enter a value for a: ");
    int b = get_int("Enter a value for b: ");
    printf("add(%i, %i) = %i\n", a, b, add(a, b));
    explain("void print_separator(void)", "Defines a function to print a separator line.");
    print_separator();
    printf("This function prints a line to separate sections of output.\n");
    explain("void explain(const char *code, const char *comment)", "Defines a function to print code and comment, then wait for user input.");
    printf("The arguments passed in (const char *code, const char *comment) are each a string of characters used to explain the code and its purpose.\n");
    printf("This function prints a code line with a comment and waits for the user to press Enter.\n");
  

    // 11. 2D Output Example (Mario)
    print_separator();
    printf("11. 2D Output Example (Mario)\n");
    explain("for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) printf(\"#\"); printf(\"\\n\"); }", "Prints a square of # characters.");
    int size = get_int("Enter a size for the square: ");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("#");
        printf("\n");
    }

    print_separator();
    printf("End of interactive fundamentals demo!\n");
    return 0;
}