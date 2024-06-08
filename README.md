# Knight Tour Problem

In this project I implement the solution of Knight Tour Problem for a board with order 8 (8x8 chess board).  

First of all, what is the Knight Tour problem?  

The problem is, given the initial position of the Knight piece, we need to find a set of moves such that it goes to all the squares on the board, passing through each one only once.  

### About the solution

To solve this problem I use the ***Warnsdorff Algorithm***. The idea is very simple. We always look for adjacencies that have the smallest number of adjacencies. This logic can be found at *check_options* function.
