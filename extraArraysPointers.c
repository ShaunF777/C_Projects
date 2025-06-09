#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

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
    printf("Welcome to the Interactive C Demo for Advanced Data Types, Declarations and Initializations!\n");
    printf("This program will guide you through  C concepts with code, comments, and interactive input.\n");
    print_separator();

    // 1. Advanced Data Types, Declarations and Initializations
    explain("int arr[5] = {1, 2, 3, 4, 5};", "Declare an array of integers with 5 elements.");
    int arr[5] = {1, 2, 3, 4, 5};
    printf("Declared arr as an array with values: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
    explain("typedef struct { int id; string name; } Person;", "Define a struct type Person with an integer id and a string name.");
    typedef struct
    {
        int id;
        string name;
    } Person;
    Person p;
    p.id = 1;
    p.name = "Alice";
    printf("Declared p as a Person with id: %i and name: %s\n", p.id, p.name);
    explain("enum Color { RED, GREEN, BLUE };", "Define an enum type Color with three values: RED, GREEN, and BLUE.");
    enum Color { RED, GREEN, BLUE };
    enum Color my_color = GREEN;
    printf("Declared my_color as Color with value: %i (GREEN)\n", my_color);
    explain("const int MAX_SIZE = 100;", "Declare a constant integer MAX_SIZE with value 100.");
    const int MAX_SIZE = 100;
    printf("Declared MAX_SIZE as a constant with value: %i\n", MAX_SIZE);
    explain("volatile int counter = 0;", "Declare a volatile integer counter, indicating it may change unexpectedly (e.g., in multi-threaded code).");
    volatile int counter = 0;
    printf("Declared counter as a volatile integer with initial value: %i\n", counter);
    explain("register int reg_var = 10;", "Declare a register variable reg_var, suggesting it should be stored in a CPU register for faster access.");
    register int reg_var = 10;
    printf("Declared reg_var as a register variable with value: %i\n", reg_var);
    explain("auto int auto_var = 20;", "Declare an auto variable auto_var, which is the default storage class in C.");
    auto int auto_var = 20;
    printf("Declared auto_var as an auto variable with value: %i\n", auto_var);
    explain("extern int global_var;", "Declare an external variable global_var, which is defined in another file or scope.");
    extern int global_var; // This would normally be defined in another file
    printf("Declared global_var as an external variable (not defined in this file).\n");
    explain("static int static_var = 30;", "Declare a static variable static_var, which retains its value between function calls.");
    static int static_var = 30;
    printf("Declared static_var as a static variable with value: %i\n", static_var);
    explain("union Data { int i; float f; char c; };", "Define a union type Data that can hold an int, float, or char, but only one at a time.");
    union Data
    {
        int i;
        float f;
        char c;
    } data;
    data.i = 42; // Assigning an int value to the union
    printf("Declared data as a union with int value: %i\n", data.i);
    explain("void *ptr;", "Declare a void pointer ptr, which can point to any data type.");
    void *ptr;
    int num = 100;
    ptr = &num; // Assigning the address of an integer to the void pointer
    printf("Declared ptr as a void pointer pointing to an integer with value: %i\n", *(int *)ptr);
    explain("size_t size = sizeof(int);", "Declare a size_t variable size and assign it the size of an int in bytes.");
    size_t size = sizeof(int);
    printf("Declared size as size_t with value: %zu (size of int in bytes)\n", size);
    explain("intptr_t intptr = (intptr_t)&num;", "Declare an intptr_t variable intptr and assign it the address of num, casting it to an integer type.");
    intptr_t intptr = (intptr_t)&num;
    printf("Declared intptr as intptr_t with value: %ld (address of num)\n", intptr);
    explain("uintptr_t uintptr = (uintptr_t)&num;", "Declare a uintptr_t variable uintptr and assign it the address of num, casting it to an unsigned integer type.");
    uintptr_t uintptr = (uintptr_t)&num;
    printf("Declared uintptr as uintptr_t with value: %lu (address of num)\n", uintptr);
    int x = 10;
    explain("int *ptr_to_int = &x;", "Declare a pointer to an integer and assign it the address of x.");
    int *ptr_to_int = &x;
    printf("Declared ptr_to_int as a pointer to int with value: %i (address of x)\n", *ptr_to_int);
    char z = 'A';
    explain("char *ptr_to_char = &z;", "Declare a pointer to a char and assign it the address of z.");
    char *ptr_to_char = &z;
    printf("Declared ptr_to_char as a pointer to char with value: %c (address of z)\n", *ptr_to_char);
    explain("string name = \"Bob\";", "Declare a string variable named name and assign it a value.");
    string name = "Bob";
    explain("string *ptr_to_string = &name;", "Declare a pointer to a string and assign it the address of name.");
    string *ptr_to_string = &name;
    printf("Declared ptr_to_string as a pointer to string with value: %s (address of name)\n", *ptr_to_string);
    explain("int **ptr_to_ptr = &ptr_to_int;", "Declare a pointer to a pointer to an integer and assign it the address of ptr_to_int.");
    int **ptr_to_ptr = &ptr_to_int;
    printf("Declared ptr_to_ptr as a pointer to pointer to int with value: %i (address of ptr_to_int)\n", **ptr_to_ptr);
    explain("void (*func_ptr)(void) = &print_separator;", "Declare a function pointer func_ptr that points to the print_separator function.");
    void (*func_ptr)(void) = &print_separator;
    printf("Declared func_ptr as a function pointer pointing to print_separator function.\n");
    explain("func_ptr();", "Call the function pointed to by func_ptr.");
    func_ptr(); // Call the function to print a separator line
    printf("Called the function pointed to by func_ptr, which prints a separator line.\n");
    explain("int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};", "Declare a 2D array of integers.");
    int arr_2d[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printf("Declared arr_2d as a 2D array with values:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%i ", arr_2d[i][j]);
        }
        printf("\n");
    }
    explain("int *arr_ptr = arr[0];", "Declare a pointer to the first element of the 2D array.");
    int *arr_ptr = arr_2d[0];
    printf("Declared arr_ptr as a pointer to the first element of the 2D array with value: %i\n", *arr_ptr);
    explain("int (*arr_ptr_2d)[3] = arr_2d;", "Declare a pointer to a 2D array.");
    int (*arr_ptr_2d)[3] = arr_2d;
    printf("Declared arr_ptr_2d as a pointer to a 2D array with first element value: %i\n", (*arr_ptr_2d)[0]);
    int y = 20; // Declare and initialize y before using it
    explain("int *arr_of_ptrs[3] = {&x, &y, &z};", "Declare an array of pointers to integers.");
    int *arr_of_ptrs[3] = {&x, &y, &z};
    printf("Declared arr_of_ptrs as an array of pointers with values: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%i ", *arr_of_ptrs[i]);
    }
    printf("\n");
    explain("int (*arr_of_ptrs_2d[3])[3] = {arr_2d[0], arr_2d[1], arr_2d[2]};", "Declare an array of pointers to 2D arrays.");
    int (*arr_of_ptrs_2d[3])[3] = {arr_2d[0], arr_2d[1], arr_2d[2]};
    printf("Declared arr_of_ptrs_2d as an array of pointers to 2D arrays with first element value: %i\n", (*arr_of_ptrs_2d[0])[0]);
    explain("int *arr_of_ptrs_2d_1d = &arr_2d[0][0];", "Declare a pointer to the first element of a 2D array, treating it as a 1D array.");
    int *arr_of_ptrs_2d_1d = &arr_2d[0][0];
    printf("Declared arr_of_ptrs_2d_1d as a pointer to the first element of a 2D array with value: %i\n", *arr_of_ptrs_2d_1d);
    explain("int *arr_of_ptrs_2d_1d_end = &arr_2d[2][2];", "Declare a pointer to the last element of a 2D array, treating it as a 1D array.");
    int *arr_of_ptrs_2d_1d_end = &arr_2d[2][2];
    printf("Declared arr_of_ptrs_2d_1d_end as a pointer to the last element of a 2D array with value: %i\n", *arr_of_ptrs_2d_1d_end);
    explain("int *arr_of_ptrs_2d_1d_range = arr_of_ptrs_2d_1d + 5;", "Declare a pointer to an element in the middle of a 2D array, treating it as a 1D array.");
    int *arr_of_ptrs_2d_1d_range = arr_of_ptrs_2d_1d + 5;
    printf("Declared arr_of_ptrs_2d_1d_range as a pointer to an element in the middle of a 2D array with value: %i\n", *arr_of_ptrs_2d_1d_range);
    explain("int *arr_of_ptrs_2d_1d_range_end = arr_of_ptrs_2d_1d + 8;", "Declare a pointer to the last element in the middle of a 2D array, treating it as a 1D array.");
    int *arr_of_ptrs_2d_1d_range_end = arr_of_ptrs_2d_1d + 8;
    printf("Declared arr_of_ptrs_2d_1d_range_end as a pointer to the last element in the middle of a 2D array with value: %i\n", *arr_of_ptrs_2d_1d_range_end);
    explain("int *arr_of_ptrs_2d_1d_range_start = arr_of_ptrs_2d_1d + 3;", "Declare a pointer to the first element in the middle of a 2D array, treating it as a 1D array.");
    int *arr_of_ptrs_2d_1d_range_start = arr_of_ptrs_2d_1d + 3;
    printf("Declared arr_of_ptrs_2d_1d_range_start as a pointer to the first element in the middle of a 2D array with value: %i\n", *arr_of_ptrs_2d_1d_range_start);
    explain("int *arr_of_ptrs_2d_1d_range_middle = arr_of_ptrs_2d_1d + 4;", "Declare a pointer to the middle element in the middle of a 2D array, treating it as a 1D array.");
    int *arr_of_ptrs_2d_1d_range_middle = arr_of_ptrs_2d_1d + 4;
    printf("Declared arr_of_ptrs_2d_1d_range_middle as a pointer to the middle element in the middle of a 2D array with value: %i\n", *arr_of_ptrs_2d_1d_range_middle);
    explain("int *arr_of_ptrs_2d_1d_range_end = arr_of_ptrs_2d_1d + 6;", "Declare a pointer to the last element in the middle of a 2D array, treating it as a 1D array.");
    int *arr_of_ptrs_2d_1d_range_end = arr_of_ptrs_2d_1d + 6;
    printf("Declared arr_of_ptrs_2d_1d_range_end as a pointer to the last element in the middle of a 2D array with value: %i\n", *arr_of_ptrs_2d_1d_range_end);
    explain("int *arr_of_ptrs_2d_1d_range_start = arr_of_ptrs_2d_1d + 2;", "Declare a pointer to the first element in the middle of a 2D array, treating it as a 1D array.");
    int *arr_of_ptrs_2d_1d_range_start = arr_of_ptrs_2d_1d + 2;
    printf("Declared arr_of_ptrs_2d_1d_range_start as a pointer to the first element in the middle of a 2D array with value: %i\n", *arr_of_ptrs_2d_1d_range_start);
    explain("int *arr_of_ptrs_2d_1d_range_middle = arr_of_ptrs_2d_1d + 3;", "Declare a pointer to the middle element in the middle of a 2D array, treating it as a 1D array.");
    int *arr_of_ptrs_2d_1d_range_middle = arr_of_ptrs_2d_1d + 3;
    printf("Declared arr_of_ptrs_2d_1d_range_middle as a pointer to the middle element in the middle of a 2D array with value: %i\n", *arr_of_ptrs_2d_1d_range_middle);
    explain("int *arr_of_ptrs_2d_1d_range_end = arr_of_ptrs_2d_1d + 4;", "Declare a pointer to the last element in the middle of a 2D array, treating it as a 1D array.");
    int *arr_of_ptrs_2d_1d_range_end = arr_of_ptrs_2d_1d + 4;
    printf("Declared arr_of_ptrs_2d_1d_range_end as a pointer to the last element in the middle of a 2D array with value: %i\n", *arr_of_ptrs_2d_1d_range_end);
}
