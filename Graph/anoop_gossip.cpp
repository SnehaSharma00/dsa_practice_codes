/*Anoop and Gossip
Difficulty: MEDIUM | Max Score: 50
Anoop lives in a university hostel. Gossip travels fast here. Once someone hears a piece of gossip, they immediately tell it to all their friends, and then those friends tell their friends, and so on. One evening, Anoop comes up with a rumor that he wants to spread across the whole hostel. But nobody is willing to start spreading it for free. Each person demands some number of chocolates before they agree to start gossiping.

The hostel has N students and M pair of friends.
Some pairs of students are friends. If one friend learns the rumor, they will pass it along to their entire circle of friends without asking for more chocolates.
To start the gossip in a circle, Anoop must bribe at least one person from that group.


Find the minimum number of chocolates Anoop needs to spend so that eventually everyone in the hostel knows the rumor.



Input Format

First line of input contains two integers N and M, representing the number of students and number of friendships.
Next line of input contains an array C where Ci represents the number of chocolates that the ith student requires to start a rumor.
Following M lines have a pair of integers (aj, bj) where 0 ≤ aj, bj < N representing a friendship between student aj and student bj.


Output Format

Print a single integer representing the minimum number of chocolates that Anoop needs to spend so that all the N students know about the rumor.


Constraints

1 ≤ N ≤ 105
0 ≤ M ≤ 105
1 ≤ Ci ≤ 109


Example 1:

Input:
6 3
7 2 4 10 6 1
0 1
1 2
4 5

Output:
13

Explanation: Students 0, 1 and 2 form a group and it is optimal to bribe student 1 with 2 chocolates. Student 3 is isolated so we need to give him 10 chocolates. Student 4 and 5 are friends and it is optimal to bribe student 5. Overall, Anoop can spread the rumor in 2 + 10 + 1 = 13 chocolates.*/

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100005;

vector<int> adj[MAX];
bool visited[MAX];
long long cost[MAX];

long long mn;

void dfs(int u)
{
    visited[u] = true;
    if(cost[u] < mn)
        mn = cost[u];

    for(int v : adj[u])
    {
        if(!visited[v])
            dfs(v);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++)
        cin >> cost[i];

    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    long long ans = 0;

    for(int i = 0; i < N; i++)
    {
        if(!visited[i])
        {
            mn = cost[i];
            dfs(i);
            ans += mn;
        }
    }

    cout << ans;

    return 0;
} 