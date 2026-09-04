#include <bits/stdc++.h>
using namespace std;

void rec(int n, string &s, vector<string>&ans, int idx){
if(idx == n){
    ans.push_back(s);
    return;
}

    for(int i=idx; i<n; i++){
        
        swap(s[i], s[idx]);
        rec(n, s, ans, idx+1);
        swap(s[i], s[idx]);
    }
    
}


int main(){

    int n;
    cin>>n;
    
    int a;
    cin>>a;

    string s = to_string(a);

    vector<string>ans;

    rec(n, s, ans, 0);
    return 0;
}
