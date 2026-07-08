/*Balanced Substrings
Difficulty: MEDIUM | Max Score: 50
You are given a string S of length N consisting only of the characters 'A', 'B', and 'C'.

Your task is to determine the number of contiguous substrings of S in which the number of occurrences of character 'A' is equal to the number of occurrences of character 'B'.

The character 'C' may appear any number of times in the substring and does not affect the condition.

Input Format

The first line contains an integer N, the length of the string.
The second line contains the string S, consisting only of characters 'A', 'B', and 'C'.

Output Format

Print a single integer — the number of contiguous substrings satisfying the condition.

Notes

A substring is valid if the count of 'A' characters is exactly equal to the count of 'B' characters within that substring.

Constraints

1 ≤ N ≤ 106

Example 1:

Input:
6
ABCCBA

Output: 10

Explanation:
Valid Substrings of length 1
"C" (3–3) → A=0, B=0
"C" (4–4) → A=0, B=0

Valid Substrings of length 2
"AB" (1–2) → A=1, B=1
"CC" (3–4) → A=0, B=0
"BA" (5–6) → A=1, B=1

Valid Substrings of length 3
"ABC" (1–3) → A=1, B=1
"CBA" (4–6) → A=1, B=1

Valid Substrings of length 4
"ABCC" (1–4) → A=1, B=1
"CCBA" (3–6) → A=1, B=1

Valid Substrings of length 6
"ABCCBA" (1–6) → A=2, B=2

Total valid substrings 2 + 3 + 2 + 2 + 1 = 10
*/