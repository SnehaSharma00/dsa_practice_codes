/*Maximum Subarray Sum
Difficulty: MEDIUM | Max Score: 50
You are given an integer array of size N.



Your task is to find the maximum possible sum of any contiguous subarray of the given array.



Input Format

The first line contains an integer N, denoting the size of the array.
The second line contains N space-separated integers representing the elements of the array.


Output Format

Print a single integer representing the maximum sum of any contiguous subarray.


Constraints

1 ≤ N ≤ 105
−109 ≤ A[i] ​≤ 109


Example 1:

Input:
4
-2 3 -1 4

Output: 6

Explanation: Possible contiguous subarrays and their sums are:
[-2] → sum = -2
[3] → sum = 3
[-1] → sum = -1
[4] → sum = 4
[-2 3] → sum = 1
[3 -1] → sum = 2
[-1 4] → sum = 3
[-2 3 -1] → sum = 0
[3 -1 4] → sum = 6
[-2 3 -1 4] → sum = 4

The maximum sum among all non-empty contiguous subarrays is 6, obtained from the subarray: [3 -1 4]*/