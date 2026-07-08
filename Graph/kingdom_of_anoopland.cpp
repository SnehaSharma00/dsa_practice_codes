/*Kingdom of Anoopland and Canals
Difficulty: MEDIUM | Max Score: 50
The Kingdom of Anoopland has a system of canals connecting all its port towns. Originally, there were N canals forming a closed loop, so that each town was directly connected to exactly two neighbors. Boats could freely travel both directions on every canal, ensuring that any town could be reached from any other. Recently, King Anoop ordered that all canals must allow travel in only one direction, to reduce accidents and regulate boat traffic. Unfortunately, this has made it impossible to reach some towns from others.

The royal engineers can reverse the flow of a canal, but each reversal costs money depending on the canal’s construction.

You are given the current directions of all canals and the cost to reverse each one. You are required to find the minimum total cost of reversing canal flows so that from every town you can reach every other town by following the canal directions?



Input Format:

First line of input contains N, the number of towns (and canals) in Kingdom of Anoopland.

Next N lines describe the canal system. Each line has 3 integers (ai, bi, ci) where the road is directed from town ai to town bi with ci being the cost to reverse it.



Output Format:

Print a single integer — the minimum total cost needed so that every town is reachable from every other.



Constraints:

3 <= N <= 105
1 <= ai, bi <= N
1 <= ci <= 100
ai ≠ bi


 

Example 1:

Input:
4
1 2 5
2 3 2
3 4 4
4 1 7

Output: 
0

Explanation: All the towns in the kingdom are well connected and reachable through a system of canals, so there is no need for spending any more money on construction.


Example 2:

Input:
5
2 1 3
2 3 4
4 3 2
4 5 5
1 5 6

Output: 
9

Explanation: If we flip the roads 2->3 and 4->5, the cost of construction would be 4 + 5 = 9. It can be shown that this is the most optimal solution.*/