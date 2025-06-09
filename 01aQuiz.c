#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int score = 0;
    int total = 10;
    bool correct[10] = {false};
    string criteria[10] = {
        "1. Comments",
        "2. Headers",
        "3. Data Types",
        "4. Variables",
        "5. Input/Output",
        "6. Arithmetic Operators",
        "7. Typecasting for Floating Point Division",
        "8. Conditionals",
        "9. Logical Operators",
        "10. Functions and 2D Output (Nested Loops)"
    };

    string examples[10] = {
        "e.g., // This is a comment",
        "e.g., #include <stdio.h>",
        "e.g., int x; float y; char c; string s;",
        "e.g., int x = 5;",
        "e.g., get_int(\"x: \"); printf(\"%i\", x);",
        "e.g., x + y, x - y, x * y, x / y, x % y",
        "e.g., (float)x / (float)y",
        "e.g., if (x < y) ... else ...",
        "e.g., if (x > 0 && y > 0) ...",
        "e.g., int add(int a, int b); for (int i = 0; i < n; i++)"
    };

    printf("Welcome to the 01aTeachMeC Quiz!\n");
    string name = get_string("What's your name? ");
    printf("Hello, %s! Let's test your C knowledge on the following topics:\n", name);
    for (int i = 0; i < total; i++)
        printf(" - %s  %s\n", criteria[i], examples[i]);

    // 1. Comments
    printf("\n1. What does this line do in C?\n");
    printf("// This is a comment\n");
    string ans1 = get_string("A) Declares a variable  B) Is ignored by the compiler  C) Runs a function\nYour answer (A/B/C): ");
    if (ans1[0] == 'B' || ans1[0] == 'b')
    {
        printf("Correct!\n");
        score++; correct[0] = true;
    }
    else
        printf("Incorrect. The correct answer is B: Comments are ignored by the compiler.\n");

    // 2. Headers
    printf("\n2. What is the purpose of #include <stdio.h> in a C program?\n");
    string ans2 = get_string("A) To include standard input/output functions  B) To declare variables  C) To end the program\nYour answer (A/B/C): ");
    if (ans2[0] == 'A' || ans2[0] == 'a')
    {
        printf("Correct!\n");
        score++; correct[1] = true;
    }
    else
        printf("Incorrect. The correct answer is A: It includes standard input/output functions.\n");

    // 3. Data Types
    printf("\n3. Which of these is NOT a basic data type in C?\n");
    printf("A) int  B) float  C) string  D) bool\n");
    string ans3 = get_string("Your answer (A/B/C/D): ");
    if (ans3[0] == 'C' || ans3[0] == 'c')
    {
        printf("Correct! (Note: 'string' is not a standard C type, but provided by CS50.)\n");
        score++; correct[2] = true;
    }
    else
        printf("Incorrect. The correct answer is C: 'string' is not a standard C type.\n");

    // 4. Variables
    printf("\n4. What is the value of x after this code?\n");
    printf("int x = 5;\nx = 7;\n");
    int ans4 = get_int("Your answer: ");
    if (ans4 == 7)
    {
        printf("Correct!\n");
        score++; correct[3] = true;
    }
    else
        printf("Incorrect. The correct answer is 7.\n");

    // 5. Input/Output
    printf("\n5. What does get_int(\"x: \") do?\n");
    string ans5 = get_string("A) Prints x  B) Reads an integer from the user  C) Declares a variable\nYour answer (A/B/C): ");
    if (ans5[0] == 'B' || ans5[0] == 'b')
    {
        printf("Correct!\n");
        score++; correct[4] = true;
    }
    else
        printf("Incorrect. The correct answer is B: It reads an integer from the user.\n");

    // 6. Arithmetic Operators
    printf("\n6. What is the result of 10 %% 3 in C?\n");
    int ans6 = get_int("Your answer: ");
    if (ans6 == 1)
    {
        printf("Correct!\n");
        score++; correct[5] = true;
    }
    else
        printf("Incorrect. The correct answer is 1 (the remainder of 10 divided by 3).\n");

    // 7. Typecasting for Floating Point Division
    printf("\n7. What is the output of this code?\n");
    printf("int x = 7, y = 2;\nprintf(\"%%.2f\\n\", (float)x / (float)y);\n");
    float ans7 = get_float("Your answer: ");
    if (ans7 > 3.49 && ans7 < 3.51)
    {
        printf("Correct!\n");
        score++; correct[6] = true;
    }
    else
        printf("Incorrect. The correct answer is 3.50.\n");

    // 8. Conditionals
    printf("\n8. What will this code print if x = 4 and y = 5?\n");
    printf("if (x < y) printf(\"A\"); else printf(\"B\");\n");
    char ans8 = get_char("Your answer (A/B): ");
    if (ans8 == 'A' || ans8 == 'a')
    {
        printf("Correct!\n");
        score++; correct[7] = true;
    }
    else
        printf("Incorrect. The correct answer is A.\n");

    // 9. Logical Operators
    printf("\n9. What is the result of (x > 0 && y > 0) if x = -1 and y = 2? (Enter 1 for true, 0 for false)\n");
    int ans9 = get_int("Your answer: ");
    if (ans9 == 0)
    {
        printf("Correct!\n");
        score++; correct[8] = true;
    }
    else
        printf("Incorrect. The correct answer is 0 (false).\n");

    // 10. Functions and 2D Output (Nested Loops)
    printf("\n10. What does this function do?\n");
    printf("void print_separator(void) { printf(\"-----\\n\"); }\n");
    string ans10 = get_string("A) Prints a separator line  B) Adds two numbers  C) Reads input\nYour answer (A/B/C): ");
    if (ans10[0] == 'A' || ans10[0] == 'a')
    {
        printf("Correct!\n");
        score++; correct[9] = true;
    }
    else
        printf("Incorrect. The correct answer is A: It prints a separator line.\n");

    // Final score and feedback
    printf("\n%s, your score is %i out of %i.\n", name, score, total);
    if (score == total)
    {
        printf("Excellent! You mastered all the concepts.\n");
    }
    else
    {
        printf("Review these topics where you made mistakes:\n");
        for (int i = 0; i < total; i++)
        {
            if (!correct[i])
                printf(" - %s\n", criteria[i]);
        }
        printf("Go back to the learning program 01aTeachMeC and review these sections.\n");
    }
    printf("Thank you for taking the quiz, %s!\n", name);
    return 0;
}