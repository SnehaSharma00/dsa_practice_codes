/*/e-kuaeshan
Difficulty: MEDIUM | Max Score: 50
You are given an integer array nums of length n and an integer k. Count the number of pairs (i, j) with i < j such that:

numsi2 - k*numsi = numsj2 - k*numsj

Input:

The first line contains an integer N and K - representing size of the array and the equation constant.

Second line contains N integers representing the elements of the array

Output:

Print the single integers representing the number of pairs satisfy the given condition.

Example:

Input: 4 8
2 4 2 6
Output: 3
Explanation: Pairs of indexes satisfying the equation are -> (0,2), (0,3), (2,3).
 
Constraints:

1 <= N <= 105
1 <= Ai <= 109
1 <= K <= 2*109

*/