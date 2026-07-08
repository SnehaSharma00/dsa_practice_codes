/*Sikong Ju and void shards
Difficulty: HARD | Max Score: 75
Sikong Jue is the last "Void Architect", a celestial engineer tasked with repairing the fractures in the multiverse. He stands before a sector of the Void represented by an N×M grid.

The Void is unstable. Some parts are solid reality (#), while others are dangerous rifts (.) that threaten to collapse the dimension. To stabilize this sector, Sikong Jue must pave every inch of the rifts using "Reality Shards."

These shards are ancient artifacts shaped like L-trominoes (covering exactly 3 unit cells). Sikong Jue follows the Code of the Architects:

Precision: Every rift (.) must be covered exactly once.
Economy: Shards cannot overlap.
Purity: Shards cannot be placed on existing reality (#).
Boundaries: Shards cannot extend beyond the grid.


Can Sikong Jue successfully seal the Void?





Input Format

The first line contains two integers N and M — the dimensions of the Void sector.
The next N lines each contain a string of length M consisting of . (empty) and # (obstacle)


Output Format

Print "YES" if it is possible to tile all empty cells perfectly. Otherwise, print "NO".



Constraints:

1 <= N , M <= 20
The grid may contain arbitrary obstacles
Time Limit: 1sec


 

Example 1:

Input:2 3
...
...
Output:YES
Explanation: The grid has 6 empty cells. Since 6 is divisible by 3, it's promising.
We can place two L-trominoes:
One covering (0,0), (0,1), (1,0) (Top-left L).
One covering (0,2), (1,1), (1,2) (Bottom-right L).
The grid is perfectly covered.


Example 2:

Input:3 3
...
.#.
...
Output:NO
Explanation: Total empty cells = 9 - 1 = 8. Since 8 is not divisible by 3 (size of a tromino), it is mathematically impossible to cover. The code should detect this immediately (Flood Fill count / Early Exit) before even trying
 */

 #include <bits/stdc++.h>
using namespace std;

struct Pl {
    int a, b, c;
};

int n, m;
vector<string> grid;
vector<Pl> placements;
vector<vector<int>> cellToPlacements;
vector<int> emptyCells;
vector<int> used;

int id(int r, int c) {
    return r * m + c;
}

bool dfs(int rem) {
    if (rem == 0) return true;

    int bestCell = -1;
    vector<int> bestCand;

    for (int idx : emptyCells) {
        if (used[idx]) continue;

        vector<int> cand;
        for (int pid : cellToPlacements[idx]) {
            Pl p = placements[pid];
            if (!used[p.a] && !used[p.b] && !used[p.c]) {
                cand.push_back(pid);
            }
        }

        if (cand.empty()) return false;

        if (bestCell == -1 || cand.size() < bestCand.size()) {
            bestCell = idx;
            bestCand = cand;
        }
    }

    for (int pid : bestCand) {
        Pl p = placements[pid];
        used[p.a] = used[p.b] = used[p.c] = 1;

        if (dfs(rem - 3)) return true;

        used[p.a] = used[p.b] = used[p.c] = 0;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    placements.clear();
    emptyCells.clear();
    cellToPlacements.assign(n * m, {});
    used.assign(n * m, 0);

    int totalEmpty = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                totalEmpty++;
                emptyCells.push_back(id(i, j));
            }
        }
    }

    if (totalEmpty % 3 != 0) {
        cout << "NO";
        return 0;
    }

    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j + 1 < m; j++) {
            int p00 = id(i, j);
            int p01 = id(i, j + 1);
            int p10 = id(i + 1, j);
            int p11 = id(i + 1, j + 1);

            if (grid[i][j] == '.' && grid[i][j + 1] == '.' && grid[i + 1][j] == '.')
                placements.push_back({p00, p01, p10});

            if (grid[i][j] == '.' && grid[i][j + 1] == '.' && grid[i + 1][j + 1] == '.')
                placements.push_back({p00, p01, p11});

            if (grid[i][j] == '.' && grid[i + 1][j] == '.' && grid[i + 1][j + 1] == '.')
                placements.push_back({p00, p10, p11});

            if (grid[i][j + 1] == '.' && grid[i + 1][j] == '.' && grid[i + 1][j + 1] == '.')
                placements.push_back({p01, p10, p11});
        }
    }

    for (int pid = 0; pid < (int)placements.size(); pid++) {
        Pl p = placements[pid];
        cellToPlacements[p.a].push_back(pid);
        cellToPlacements[p.b].push_back(pid);
        cellToPlacements[p.c].push_back(pid);
    }

    cout << (dfs(totalEmpty) ? "YES" : "NO");
    return 0;
}