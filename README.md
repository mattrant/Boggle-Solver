# Boggle-Solver
This repoository is a C++ implementation of a Boggle solver. The code generates a random 4x4 Boggle board and finds all of the words that are present on the board that are also in the file `engmix.txt`.
On running the code, the board that was generated is printed to the console followed by all of the words that were found.

Running the code requires `g++` and at least C++11. After navigating into the folder containing the code,
```bash
make
./boggle
```
An abbreviated example output looks like

```bash
D  L  Y  L  
E  A  E  M  
B  I  L  N  
M  E  E  T  
Words of length 3
ABE
AIL
AIM
ALE
.
.
.
Words of length 4
ABED
ABEL
BADE
BAIL
.
.
.
````
