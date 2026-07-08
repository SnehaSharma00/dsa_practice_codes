/*Array Gap
Difficulty: MEDIUM | Max Score: 50
You are given two sequences of positive integers:

An array A of length N.
An array B of length M.


Your task is to determine the minimum absolute difference between any element of array A and any element of array B.



Formally, find:

 1 ≤ i ≤ N,1 ≤ j ≤ M  min​(|Ai​−Bj|​)



Input Format

The first line contains two integers N and M, representing the sizes of arrays A and B.
The second line contains N positive integers A1, A2, … , AN​.
The third line contains M positive integers B1​, B2 , … , BM​.


Output Format

Print a single integer representing the minimum absolute difference between any element of array A and any element of array B.


Constraints

1 ≤ N , M ≤ 2×105
1 ≤ Ai ​≤ 109
1 ≤ Bi ​≤ 109
All values in input are integers.


Example 1:

Input:
2 2
1 6
4 9

Output: 2

Explanation: Here is the difference for each of the four pair of an element of A and an element of B: 
∣1−4∣ = 3, ∣1−9∣ = 8, ∣6−4∣ = 2, and ∣6−9∣ = 3. We should print the minimum of these values, or 2.


Example 2:

Input:
6 8
82 76 82 82 71 70
17 39 67 2 45 35 22 24

Output: 3*/