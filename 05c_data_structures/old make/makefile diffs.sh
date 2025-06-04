# Make file from leaving the flock
gcc  -g -Wall -lcs50    hello1.c   -o hello1

# make file from downloaded libcs50 
cc -Wall -Wextra -Werror -pedantic -std=c11    hello1.c   -o hello1

# make file Tian made
gcc -Wall -Wextra -Werror -std=c11 -c hello1.c -o hello1.o
gcc -Wall -Wextra -Werror -std=c11 -o hello1 hello1.o -lcs50