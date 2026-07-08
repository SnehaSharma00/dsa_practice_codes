/*Odd Prime Pairs
Difficulty: MEDIUM | Max Score: 50
You are given an array A of size N consisting only of prime numbers.
You are also given Q queries.

Each query consists of two integers L and R (1 ≤ L ≤ R ≤ N).
For each query, determine the number of pairs (i, j) such that:

L ≤ i < j ≤ R
A[i] + A[j] is odd.

Input Format

The first line contains an integer N, the size of the array.
The second line contains N prime numbers representing the array A.
The third line contains an integer Q, the number of queries.
The next Q lines each contain two integers L and R.

Output Format

For each query, output a single integer — the number of valid pairs whose sum is odd.

Constraints

1 ≤ N, Q ≤ 2 * 105
1 ≤ L ≤ R ≤ N
2 ≤ A[i] ≤ 100
N, Q, L, and R are integers.
 
Example 1:

Input:
6
2 3 5 2 7 11
3
1 6
2 5
3 4

Output:
8
3
1

Explanation:
Query 1: (L = 1, R = 6)
The valid pairs (𝑖,𝑗)  whose sum is odd are:
(1, 2) (1, 3) (1, 5) (1, 6) , (2 , 4) , (3 , 4) , (4 , 5) , (4 , 6)
There are 8 such pairs in total.
Output: 8

*/