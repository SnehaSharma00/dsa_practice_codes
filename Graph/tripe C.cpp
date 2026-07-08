/*Triple-C
Difficulty: MEDIUM | Max Score: 50
You are given a Graph of N nodes numbered from 1 to N and M bidirectional edges.

Your task is to do Triple-C task for the given Graph.

Note: Here Triple-C means to Count Connected Components in the given Graph.



Pro-Tip for Python Users: Because graphs can be very deep, standard recursive DFS might trigger a RecursionError. To prevent this, add these two lines at the very top of your Python code:

import sys

sys.setrecursionlimit(200000)



Input Format:

The first line contains two integers N and M - representing the number of nodes and edges in the given graph

Next M lines contains 2 integers each - representing the two nodes which are connected by the i-th bidirectional edge.



Output Format:

Print an integer denoting the number of connected components that graph is having.

 

Example:

Input: 8 6
2 5
4 6
1 5
2 1
4 8
4 3
Output: 3
Explanation: The graph will be like:
 _____________________________________
|        2         6--4--8            |
|       / \           |               |
|      5---1          3          7    |
|_____________________________________|
 

Constraints:

1 <= N <= 104
0 <= M <= min( 105, N*(N-1) / 2 )
1 <= Ui , Vi <= N
No self loops in the graph*/

