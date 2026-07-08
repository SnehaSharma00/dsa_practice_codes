/*Alien Colony Shield Perimeter
Difficulty: MEDIUM | Max Score: 50
An alien colony is built on a grid-based planetary surface, where:

1 represents an energy shield barrier protecting the colony.
0 represents the hostile outer space surrounding the colony.


The colony's shield is completely surrounded by outer space and consists of one continuous structure (i.e., all shield segments are connected either vertically or horizontally, not diagonally).

There are no enclosed unshielded zones inside the colony (i.e., no trapped spaces).



Each shield segment is a 1x1 energy module, and the goal is to determine the total exposed perimeter of the shield structure, which is the sum of all segments exposed to space.



Note: The region outside the grid is also considered as outer space.



Input Format

The first line contains two integers, R and C — the number of rows and columns in the planetary grid.
The next R lines contain C space-separated integers, where 1 represents a shield module and 0 represents outer space.


Output Format

Print a single integer representing the total exposed perimeter of the colony's shield.


Constraints

1 ≤ R, C ≤ 100
grid[i][j] is 0 or 1.
There is exactly one continuous shield structure in the grid.


Example 1:

Input:
4 4 
0 1 0 0 
1 1 1 0 
0 1 0 0 
1 1 0 0 

Output:
16 

Explanation: The alien shield structure has 16 exposed segments facing open space.


Example 2:

Input:
1 1 
1 

Output:
4 

Explanation: A single 1×1 shield module is fully exposed on all four sides in outer space.


Example 3:

Input:
1 2 
1 0 

Output:
4 
Explanation: The single shield module at (1,1) has four exposed sides, making the total perimeter 4.*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
 int R, C;
    cin >> R >> C;

    int grid[100][100];

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> grid[i][j];

    int perimeter = 0;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 1) {
                perimeter += 4;
                for (int k = 0; k < 4; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 1)
                        perimeter--;
                }
            }
        }
    }

    cout << perimeter;
    return 0;
}