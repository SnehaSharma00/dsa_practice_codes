#include <bits/stdc++.h>
using namespace std;

//array of vectors
vector<int> adj[n];

//vector of fixed size arrays 
vector<array<int, 3>> edges;

//custom comparator
bool cmp(int a, int b){
    return a>b;
}
