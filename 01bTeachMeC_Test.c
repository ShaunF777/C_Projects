#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int score = 0;
    int total = 10;
    bool correct[10] = {false};
    string criteria[10] = {
        "Arithmetic Operators",
        "Modulo Operator",
        "Logical Operators",
        "Relational Operators",
        "Conditional Statements",
        "Ternary Operator",
        "Switch Statement",
        "For Loop",
        "While/Do-While Loop",
        "String Functions"
    };

    printf("Welcome to the C Fundamentals Quiz!\n");
    string name = get_string("What's your name? ");
    printf("Hello, %s! Let's test your C knowledge.\n", name);

    // 1. Arithmetic Operators
    printf("\n1. What is the value of x after this code?\n");
    printf("int x = 3;\nx *= 4;\n");
    int ans1 = get_int("Your answer: ");
    if (ans1 == 12)
    {
        printf("Correct!\n");
        score++; correct[0] = true;
    }
    else
        printf("Incorrect. The correct answer is 12.\n");

    // 2. Modulo Operator
    printf("\n2. What is the result of 17 %% 5?\n");
    int ans2 = get_int("Your answer: ");
    if (ans2 == 2)
    {
        printf("Correct!\n");
        score++; correct[1] = true;
    }
    else
        printf("Incorrect. The correct answer is 2.\n");

    // 3. Logical Operators
    printf("\n3. What is the result of (5 > 3 && 2 < 1)? (Enter 1 for true, 0 for false)\n");
    int ans3 = get_int("Your answer: ");
    if (ans3 == 0)
    {
        printf("Correct!\n");
        score++; correct[2] = true;
    }
    else
        printf("Incorrect. The correct answer is 0 (false).\n");

    // 4. Relational Operators
    printf("\n4. What does the expression (7 != 7) evaluate to? (Enter 1 for true, 0 for false)\n");
    int ans4 = get_int("Your answer: ");
    if (ans4 == 0)
    {
        printf("Correct!\n");
        score++; correct[3] = true;
    }
    else
        printf("Incorrect. The correct answer is 0 (false).\n");

    // 5. Conditional Statements
    printf("\n5. If x = 10 and y = 20, what will this code print?\n");
    printf("if (x < y) printf(\"A\"); else printf(\"B\");\n");
    char ans5 = get_char("Your answer (A/B): ");
    if (ans5 == 'A' || ans5 == 'a')
    {
        printf("Correct!\n");
        score++; correct[4] = true;
    }
    else
        printf("Incorrect. The correct answer is A.\n");

    // 6. Ternary Operator
    printf("\n6. What value does z get in this code?\n");
    printf("int x = 5, y = 8;\nint z = (x > y) ? x : y;\n");
    int ans6 = get_int("Your answer: ");
    if (ans6 == 8)
    {
        printf("Correct!\n");
        score++; correct[5] = true;
    }
    else
        printf("Incorrect. The correct answer is 8.\n");

    // 7. Switch Statement
    printf("\n7. What will this code print if n = 2?\n");
    printf("switch(n) { case 1: printf(\"One\"); break; case 2: printf(\"Two\"); break; default: printf(\"Other\"); }\n");
    string ans7 = get_string("Your answer: ");
    if (strcmp(ans7, "Two") == 0 || strcmp(ans7, "two") == 0)
    {
        printf("Correct!\n");
        score++; correct[6] = true;
    }
    else
        printf("Incorrect. The correct answer is Two.\n");

    // 8. For Loop
    printf("\n8. How many times will this loop print \"Hi\"?\n");
    printf("for (int i = 0; i < 4; i++) printf(\"Hi\");\n");
    int ans8 = get_int("Your answer: ");
    if (ans8 == 4)
    {
        printf("Correct!\n");
        score++; correct[7] = true;
    }
    else
        printf("Incorrect. The correct answer is 4.\n");

    // 9. While/Do-While Loop
    printf("\n9. What is the main difference between a while loop and a do-while loop?\n");
    printf("A) do-while always runs at least once\nB) while always runs at least once\nC) No difference\n");
    char ans9 = get_char("Your answer (A/B/C): ");
    if (ans9 == 'A' || ans9 == 'a')
    {
        printf("Correct!\n");
        score++; correct[8] = true;
    }
    else
        printf("Incorrect. The correct answer is A.\n");

    // 10. String Functions
    printf("\n10. What does strcmp(\"cat\", \"cat\") return?\n");
    int ans10 = get_int("Your answer: ");
    if (ans10 == 0)
    {
        printf("Correct!\n");
        score++; correct[9] = true;
    }
    else
        printf("Incorrect. The correct answer is 0.\n");

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
        printf("Go back to the learning program and review these sections.\n");
    }
    printf("Thank you for taking the quiz, %s!\n", name);
    return 0;
}