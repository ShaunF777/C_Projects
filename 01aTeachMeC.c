#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Helper function to print code and comment, then wait for user
int add(int a, int b)
{
    return a + b;
}

void print_separator(void)
{
    printf("\n---------------------------------------------\n");
}

void explain(const char *code, const char *comment)
{
    printf("\nCODE:    %s\n", code);
    printf("COMMENT: %s\n", comment);
    printf("Press Enter to continue...\n");
    getchar();
}

int main(void)
{
    print_separator();
    printf("Welcome to the Interactive C Fundamentals Demo!\n");
    printf("This program will guide you through basic C concepts with code, comments, and interactive input.\n");
    print_separator();
    
    
    // 1. Comments, Input/Output and Headers
    print_separator();
    printf("1. Comments, Input/Output and Headers\n");
    explain("// This is a single-line comment", "Comments are ignored by the compiler and help explain code to humans.");
    explain("#include <cs50.h>\n#include <stdio.h>", "Include headers for input/output and CS50 functions like get_string and get_int.");
    explain("#include <stdio.h>", "Headers are shortcuts for other .c file libraries.\n"
        "These libraries provide abstracted functions we need localy.");
    
    explain("string answer = get_string(\"What's your name? \");", "Prompt the user for their name and store it as a string.");
    string answer = get_string("What's your name? ");
    printf("Hello, %s! Let's get started. It's best to follow the .c code while doing the exercise.\n", answer);
   
    // 2. Basic Data Types, Declarations and Variables
    print_separator();
    printf("2. Basic Data Types, Declarations and Variables\n");
    explain("int e = 5;", "Declare an integer variable e and assign it the value 5.");
    int e = 5;
    printf("Declared x as an integer with value: %i\n", e);
    explain("float f = 3.14;", "Declare a float variable f and assign it the value 3.14.");
    float f = 3.14;
    printf("Declared f as a float with value: %.2f\n", f);
    explain("char g = 'A';", "Declare a char variable g and assign it the character 'A'.");
    char g = 'A';
    printf("Declared g as a char with value: %c\n", g);
    explain("string name = \"Alice\";", "Declare a string variable name and assign it the value \"Alice\".");
    string name = "Alice";
    printf("Declared name as a string with value: %s\n", name);
    explain("bool is_valid = true;", "Declare a boolean variable is_valid and assign it the value true.");
    bool is_valid = true;
    printf("Declared is_valid as a boolean with value: %s\n", "true");

    // 3. Arithmetic Operators
    printf("3. Arithmetic Operators and syntax\n");
    explain("int x = get_int(\"x: \");\n         int y = get_int(\"y: \");", "Prompt the user for two integers.");
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
        printf("Modulo: %i %% %i = %i as the remainder is %i when deviding %i by %i.\n", x, y, x % y, x % y, x, y);
    else
        printf("Cannot modulo by zero!\n");

    // 4. Typecasting for Floating Point Division
    print_separator();
    printf("4. Typecasting for Floating Point Division\n");
    explain("float z = (float)x / (float)y;", "Convert x and y to float for decimal division.");
    if (y != 0)
        printf("Floating point division: %.2f / %.2f = %.5f\n", (float)x, (float)y, (float)x / (float)y);
    else
        printf("Cannot divide by zero!\n");

    // 5. Conditionals
    print_separator();
    printf("5. Conditionals\n");
    explain("if (x < y) ... else if (x > y) ... else ...", "Compare x and y and print the relationship.");
    printf("IF the condition(x < y) is true, \n"
        "   THEN execute the following code, \n"
        "   ELSE IF this condition is true, \n"
        "   THEN execute the following alternative code.\n");
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

    // 6. Logical Operators
    print_separator();
    printf("6. Logical Operators\n");
    explain("if (x > 0 && y > 0) ...", "&& means AND. Checks if both x and(&&) y are positive.");
    printf("Remember that C uses logical operators to combine conditions into one single condition.\n");
    printf("Logical operators: && means AND, || means OR, ! means NOT.\n");
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

    // 7. Functions
    print_separator();
    printf("7. Functions\n");
    explain("int main(void)", "\"int\" Means it will return an integer value.\n" 
        "\"main\"Is the primary program function.\n "
        "\"(void)\" Means no initial arguments are passed into the function.\n");
    printf("The \"main\" function is where the program starts executing.\n");
    explain("In any function \"return 0;\"", "Indicates successful program termination.");
    printf("Returning 0 from main indicates that the program completed successfully.\n");
    explain("int add(int a, int b) { return a + b; }", "Defines a function to add two integers.");
    int a = get_int("Enter a value for a: ");
    int b = get_int("Enter a value for b: ");
    printf("Look at the 1st function in the .c code. add(%i, %i) = %i\n", a, b, add(a, b));
    explain("Now look at the 2nd function: void print_separator(void)", "Defines a function to print a separator line.");
    print_separator();
    printf("This function prints a line to separate sections of output.\n");
    explain("The 3rd function is mostly used here: void explain(const char *code, const char *comment)", "Defines a function to print code and comment, then wait for user input.");
    printf("The arguments passed in (const char *code, const char *comment)\n" 
        "are each a string of characters used to explain the code and its purpose.\n");
    printf("This function prints a code line with a comment and waits for the user to press Enter.\n");
    explain("int add(int a, int b);", "This is a function prototype (declaration), telling \n" 
        "the compiler that a function named 'add' exists and takes two int arguments.");
    printf("You can declare a function at the top of your file, then define it later.\n");

    // 8. Nested for loops. 2D Output Example (Mario)
    print_separator();
    printf("8. Nested for loop: 2D Output Example (Mario)\n");
    explain("for (int i = 0; i < n; i++) \n"
        "   { for (int j = 0; j < n; j++) \n"
        "       printf(\"#\");\n"
        "       printf(\"\\n\"); }", "Prints a square of # characters.\n"
        "The outer loop iterates over rows, and the inner loop iterates over columns.");
    int size = get_int("Enter a size for the square: ");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("#");
        printf("\n");
    }

    print_separator();
    printf("We have covered some basics of C programming including:\n" 
        "Comments & headers for input/output\n"
        "Arithmetic operations\n"
        "Typecasting floats\n"
        "Conditionals\n"
        "Logical operators\n"
        "Functions and loops.\n");
    printf("This is the end of the fundamentals demo 01aTeachMeC.\n"
        "Please execute the 01aQuiz to test your knowledge?\n");
    return 0;
}