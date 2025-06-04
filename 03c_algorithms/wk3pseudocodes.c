//Selection Sort:
array[n] = {0, 1, 2, 3, .... n-3, n-2, n-1}
outer loop - for i from 0 to n-1
    inner loop - Find smallest number between numbers[i] and numbers[n-1]
                Swap smallest number with numbers[i]
or
for (i = 0 ; i < n-1, i++)
{
    int temp = 0;
    if numbers[i] < numbers[i+1]
    {
        temp = numbers[i]
    }
}
amount of steps (n-1)+(n-2)+(n-3)+...+1
or formulated as n(n-1)/2

//Bubble sort an array small to large:
array[n] = {0, 1, 2, 3, .... n-3, n-2, n-1}
outer loop - Repeat n-1 times
inner loop - for i from 0 to n-2
            if numbers[i] > numbers[i+1] (is out of order)
                        Swap numbers[i] with numbers[i+1]
            if no swaps
                    Quit

//Recursion search for number 50 behind doors
if no doors left    // must check this as 1st step
    return false;   // this is base case
if number behind middle door
    return true
else if number < middle door
    search left half
else if number > middle door
    search right half

//Recursion search in phonebook for a person
1 Pick up phonebook
2 Open to middle of phone book
3 Look at page
4 If person is on page // base case to end search function, simplest form or result reached
5   Call person
6  Else if person is earlier in book
7     search left half of book //start search loop again 2 Open to middle of left half of book
8                               //3 Look at page
9  Else if person is later in book
10    search right half of book //start search loop again 2 Open to middle of right half of book
11                               //Go back to line 3
12 Else
13    Quit

Merge sort (to sort a number into sequence)
If only one number // base case
    Quit
Else
    Sort left of numbers// Recursion using half of the array
    Sort right of numbers// Recursion using half of the array
    Merge sorted halves // Using a new array, stich together the 2 halves,  comparing and putting the smallest 1st every time

Merge sorting
origenal array0: 63415270                       // how to sort array of size 8?
//split and make new array of left, same with right
array1          6341    &   5270                // how to sort array[4]?
//split and make new array of left, same with right
arr2      63   &    41      &   52     &   70   // how to sort array[2]?
//split and make new array of left, same with right
ar3    6 & 3   &   4 & 1   &   5 & 2  &  7 & 0  // base case reached = array[1]
// because these are already sorted into array[1]'s, next step
// now do merge comp reusing array2
arr2      36   &    14      &   25     &   07
// now do merge comp reusing array1
array1        6341    &   5270
// now do merge comp using original or final array4
origenal array0:  01234567

/* Selection sort stayed inside one array, only using constant amount of memory, making changes one variable at a time
 Selection sort was keeping track who was the smallest number
 Bubble sort did the same just keeping track of i and i+1, not allowing any more memory
 in programming more memory can make things run faster
*/
pseudocodes 
