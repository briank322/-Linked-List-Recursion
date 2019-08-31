<teams.cpp>
---------------------------------------------------------------------------
program that reads in a text file containing an integer, n, (which will always be an even number) followed by n single-word names (separated by any amount of whitespace) and then outputs all possible combinations of 2 teams that can be formed from the given names.

The following is a sample input and output of the program.

Input text file: teams1.in
4
Steph Russell  James
Lebron
Compiling the program
$ g++ -g -Wall teams.cpp -o teams
Running the program and the output
$ ./teams teams1.in
Combination 1
T1: Steph Russell
T2: James Lebron

Combination 2
T1: Steph James
T2: Russell Lebron

Combination 3
T1: Steph Lebron
T2: Russell James

Combination 4
T1: Russell James
T2: Steph Lebron

Combination 5
T1: Russell Lebron
T2: Steph James

Combination 6
T1: James Lebron
T2: Steph Russell

<wserach.cpp>
-------------------------------------------------------------------------------
a word search solver. Given a grid of characters and a target word, find all occurrences of a target word (of at least 2 characters) in the grid either vertically or horizontally (in either direction) by listing the row and column (using 0-based indexing) where the first character starts and in what direction the word extends.

For example, given the grid below and the target word snow the output should be as shown

a p s d z\n
c d n i b\n
s n o w a\n
j b w o w\n
Desired output for the target word snow should be:

snow starts at (row,col) = (0,2) and proceeds down.
snow starts at (row,col) = (2,0) and proceeds right.
For the target word won the output should be:

won starts at (row,col) = (2,3) and proceeds left.
won starts at (row,col) = (3,2) and proceeds up.
For the target word wow the output should be:

wow starts at (row,col) = (3,2) and proceeds right.
wow starts at (row,col) = (3,4) and proceeds left.

