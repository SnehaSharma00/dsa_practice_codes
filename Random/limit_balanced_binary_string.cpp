/*Limit Balanced Binary String
Difficulty: MEDIUM | Max Score: 50
Write a program that takes an integer L and a binary string S as input. Your program should determine whether the given string is Limit Balanced.



A binary string contains only 0s and 1s.



A string is called Limit Balanced if for every subarray whose length is greater than L, the subarray contains at least one '0' and at least one '1'.

In other words, no subarray of length greater than L should consist of only 0s or only 1s.



Your program should output "YES" if the string is Limit Balanced, otherwise output "NO".



Input Format

The first line contains an integer L, the limit.
The second line contains a binary string S consisting of characters '0' and '1'.


Output Format

Output YES if the string is Limit Balanced. Otherwise output NO.


Constraints

1≤∣S∣≤2×105
1≤L≤∣S∣
The string S contains only 0 and 1.


Example 1:

Input:
2
010101

Output:
YES

Explanation:
Every Subarray greater than size 2 contains atleast 1 ones and 1 zeros*/