//https://cses.fi/problemset/task/1648

//fenwik treeeor BITtree

/*given an array of length n, and Q queries, answer each query.

Queries can be of type:
Given l, r find the sum of the range with indexes from l to r
Given i and v , update the value of a[i] to v

COnstraints:

*/

/*
A ->  0  8  -2  3  1  13  -8  12  10  7  18  -9  11  9  21  17  -12
         _      _     _       _      _       _       _      _
         _____       _______         ______         _______
         ___________                 _______________                
         ____________________________
         __________________________________________________________
     0  8      3     13      12      7      -9      9      17
            6             5              25             30

FT->  0  8  6  3  10  13  5  12  37   7  25  -9  27  9  30 17   99
index 0  1  2  3  4   5  6   7   8   9  10   11  12 13  14 15  16  

Q: find sum till index 13
index = 13 -> 1101 
make rightmost 1 to 0 ->1100 = 12
rightmost 1 to 0 -> 1000 = 8
prefsum (13) =FT[13] +  FT[12] + FT[8] = 37

Q: update index 5 : add 2 to it
5 -> 101 
add 2^ pos of rightmost 1 -> 5 + 2^0 = 6 
update 6
repeat 

A: index = 5(101) + 2^0 = 6(110) + 2^1 = 8(1000) + 2^3 = 16 + 2^4 = 32
therefore , if updating index 5 , also update index 6, 8, 16.


all functions which are invertible can be solved using pref arr or fenwik tree . eg AND isnt invertible
TC: O(log n)
*/
#include <iostream>
#include <vector>
using namespace std;

long long pre(int index, vector<long long>& fenwick){
    long long ans = 0;
    while(index > 0){
        ans += fenwick[index];
        index -= (index & -index);
    }
    return ans;
}

void update(int index, long long val, vector<long long>& fenwick){
    int n = fenwick.size() - 1;
    while(index <= n){
        fenwick[index] += val;
        index += (index & -index);
    }
}

int main(){
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    vector<long long> fenwick(n + 1, 0);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        update(i + 1, a[i], fenwick);

    while(q--){
        int type, c;
        long long b;
        cin >> type >> c >> b;

        if(type == 1){
            long long delta = b - a[c - 1];
            a[c - 1] = b;
            update(c, delta, fenwick);
        }
        else{
            cout << pre(b, fenwick) - pre(c - 1, fenwick) << '\n';
        }
    }
}