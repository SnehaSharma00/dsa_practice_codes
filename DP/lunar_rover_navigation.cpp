/*Lunar Rover Navigation
Difficulty: MEDIUM | Max Score: 50
"Navigation is the key" ~do4Z
A lunar rover has landed on a grid-like sector of the moon of size N * M. The rover starts at the top-left coordinate (0, 0) and must reach the extraction zone at the bottom-right coordinate (N-1, M-1). It can only move South (down) or East (right).

Each cell in the grid has a specific elevation level given by E[i][j].

The rover's battery is consumed based on the change in elevation. When moving from a current cell to a valid adjacent cell, the battery consumed is exactly the absolute difference in their elevations:  

|Ecurrent - Enext|



Calculate the minimum battery energy the rover must consume to reach the extraction zone.





Input Format:

The first line contains two integers N and M.
The next N lines contain M space-separated integers representing the elevation grid E.


Output Format:

Print a single integer representing the minimum battery energy consumed.




 

Example:

Input: 3 3
1 2 5
4 3 6
5 4 7
Output: 6
Explanation: Let's trace a path. Start at (0,0) elevation 1. Path: (0,0) -> (0,1) -> (1,1) -> (2,1) -> (2,2) Elevations: 1 -> 2 -> 3 -> 4 -> 7 
Energy costs: |1-2| + |2-3| + |3-4| + |4-7| = 1 + 1 + 1 + 3 = 6.
 

Constraints:

1 <= N , M <= 103
0 <= E[i][j] <= 109*/