<teams.cpp>
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
----------------------------------------------------------------------------
