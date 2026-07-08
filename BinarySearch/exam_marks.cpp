/*Exam Marks
Difficulty: MEDIUM | Max Score: 50
Nobita is taking an exam consisting of n questions. Each answer is either correct or incorrect.

A correct answer is represented by 1.
An incorrect answer is represented by 0.
Doraemon gives Nobita a gadget that allows him to flip at most k incorrect answers (0s) into correct ones (1s).



Your task is to determine the maximum number of consecutive correct answers Nobita can achieve after using the gadget optimally.



Input Format

The first line contains an integer n, the number of questions.
The second line contains n space-separated integers representing the array nums.
The third line contains an integer k, the maximum number of 0s that can be flipped.


Output Format

Print a single integer — the maximum number of consecutive 1s that can be obtained. 


Constraints

1 ≤ n ≤ 105
nums[i] is either 0 or 1.
0 ≤ k ≤ n


Example 1:

Input:
11 
1 1 1 0 0 0 1 1 1 1 0 
2 

Output: 6 

Explanation: Nobita can flip two 0s to 1s, making the sequence:
1 1 1 0 0 1 1 1 1 1 1 
The longest streak of 1s is 6.


Example 2:

Input:
19 
0 0 1 1 0 0 1 1 1 0 1 1 0 0 0 1 1 1 1 
3 

Output: 10 

Explanation: Nobita flips three 0s, resulting in:
0 0 1 1 1 1 1 1 1 1 1 1 0 0 0 1 1 1 1 
The longest streak of 1s is 10.


Example 3:

Input:
10 
1 0 0 1 0 1 1 0 0 1 
4 

Output: 8

Explanation: Nobita flips four 0s, resulting in:
The longest streak of 1s is 8
1 1 1 1 1 1 1 1 0 1 */


// we need to make a monotonous data first
// we need to find max subarray that has at max k 0s 
//make prefsum array for count of 0s
// 