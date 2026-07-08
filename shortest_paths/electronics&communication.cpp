/*Electronics and Communication
Difficulty: MEDIUM | Max Score: 50
You are given a directed network of N nodes, labeled from 1 to N. You are also given M directed edges representing the connections between these nodes. Each connection is given as a triplet U, V, and W, which means it takes W units of time for a signal to travel from source node U to target node V.

We will send a signal from a specific starting node K. Your task is to determine the minimum time it takes for all N nodes in the network to receive the signal. If it is impossible for all N nodes to receive the signal (i.e., the graph is disconnected or certain nodes are unreachable from K), print -1.



Input Format:

The first line contains three space-separated integers: N (number of nodes), M (number of directed edges), and K (the starting node).
The next M lines each contain three space-separated integers U, V, and W, representing a directed edge from U to V with a travel time of W.
Output Format:

Print a single integer representing the minimum time required for all nodes to receive the signal. Print -1 if it is impossible.




 

Example :

Input: 4 3 2
2 1 1
2 3 1
3 4 1
Output: 2
Explanation: The signal starts at node 2.
It reaches node 1 in time 1.
It reaches node 3 in time 1.
From node 3, it propagates to node 4, taking an additional time of 1 (total time = 1 + 1 = 2). All nodes have received the signal by time 2, so the answer is 2.
 

Constraints:

1 <= N <= 105
1 <= M <= 2 * 105
1 <= K <= N
1 <= U, V <= N
0 <= W <= 104
There can be multiple edges between two nodes, and there can be self-loops.*/