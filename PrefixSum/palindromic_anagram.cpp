/*
Palindromic Anagrams
Difficulty: MEDIUM | Max Score: 50
You are given a string S of length N consisting of lowercase Latin letters ('a' to 'z').

You are also given Q queries.

Each query contains two integers L and R (1 ≤ L ≤ R ≤ N), representing a substring S[L…R].

For each query, determine whether there exists any anagram of the substring S[L…R] that forms a palindrome.

If such an anagram exists, print "YES", otherwise print "NO".

Explanation of Anagram

An anagram of a string is another string formed by rearranging its characters without adding or removing any characters.

For example:

"aab" → "aba" (anagram)
"abc" → "cba" (anagram)

Input Format

First line contains an integer N.
Second line contains the string S.
Third line contains an integer Q.
Next Q lines contain two integers L and R.
Output Format

For each query, print "YES" or "NO" on a new line.
Constraints

1 ≤ N,Q ≤ 2×105
1 ≤ L ≤ R ≤ N
String contains only lowercase English letters.


Example 1:

Input:
7
aabbcad
4
1 4
1 3
2 6
4 7

Output:
YES
YES
YES
NO

Explanation:
Query 1: (L = 1, R = 4) → substring = "aabb"
Character frequencies: a=2, b=2
All characters occur even number of times, so an anagram like "abba" is a palindrome.
Answer: YES

Query 4: (L = 4, R = 7) → substring = "bcad"
Character frequencies: b=1, c=1, a=1, d=1
More than one odd frequency exists, so palindrome is not possible.
Answer: NO*/