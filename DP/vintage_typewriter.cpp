/*The Vintage Typewriter
Difficulty: MEDIUM | Max Score: 50
"If I could replace the letters on keyboard to some other letter then I would have replaced it with U " ~do4Z
A cryptographer is using a vintage typewriter to type out a sequence of N secret characters. The typewriter is a bit rusty and has two modes of typing:

Single Keystroke: Typing the i-th character individually takes S[i] milliseconds.
Combo Keystroke: The typewriter has a mechanical quirk. You can press two adjacent keys simultaneously to type the i-th and (i+1)-th characters together. This combo maneuver takes C[i] milliseconds.
Given the time it takes to type each character individually, and the time it takes to type any two adjacent characters as a combo, find the minimum total time required to type the entire sequence of N characters.





Input Format:

The first line contains an integer N (the number of characters).
The second line contains N integers representing the array S (Single stroke times).
The third line contains N-1 integers representing the array C (Combo stroke times, where C[i] is the time to type character i and i+1 together).


Output Format:

Print a single integer representing the minimum time to type all N characters.




 

Example:

Input: 4
10 15 20 10
12 30 15
Output: 27
Explanation: Option 1 (All singles): 10 + 15 + 20 + 10 = 55 ms.
Option 2 (Combo first two, single last two): C[0] + S[2] + S[3] = 12 + 20 + 10 = 42 ms.
Option 3 (Combo first two, combo last two): C[0] + C[2] = 12 + 15 = 27 ms. The minimum time is 27.
 

Constraints:

1 <= N <= 105
1 <= S[i] , C[i] <= 109*/