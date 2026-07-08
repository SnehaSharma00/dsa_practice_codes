/*Add Space To String
Difficulty: MEDIUM | Max Score: 50
Anoop has been told by some hermit that he should change his name for success in his life. Anoop has come up with a bunch of new names. The hermit had also asked him to add a space before some of the consonants in the new name.



He wants to know for each of the names that he has come up with, what are the different names that could be made by appending a space in front of some of the consonants. Can you help him figure it out?



Input Format

The first line of input consists of a number N which shows the number of characters in the input string.
The second line of input consists of a string S which consists of uppercase English alphabets only.


Output Format

Output the different strings that can be made from the given string, each in a separate line.
Print the strings in lexicographical order. Space is considered lexicographically smaller than any English characters.


Constraints

1 ≤ N ≤ 20


Example 1:

Input:
3
BAC

Output:
 BA C
 BAC
BA C
BAC

Explanation: There are 2 consonants in the given string "B" and "C". We are allowed to add space before these two consonants. So, in total we have the following cases:
1. No space before B and no space before C - giving us "BAC"
2. No space before B and a space before C - giving us "BA C"
3. A space before B and no space before C - giving us " BAC"
4. A space before both B and C - giving us " BA C"

Lexicographically, we get " BA C", " BAC", "BA C", "BAC".*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool isVovel(char c){
    if(c=='A'|| c=='E'|| c=='I'||c=='O'||c=='U')return true;
    else return false;
}
void rec(int i, string s , string curr,vector<string> &ans){
    if(i==s.size()){
        ans.push_back(curr);
        return;
    }
    char c = s[i];
    if(isVovel(c)){
        rec(i+1, s, curr+ c, ans);
    }
    else{
        rec(i+1, s, curr+c, ans);
        rec(i+1, s, curr + " "+ c, ans);
    }
}
int main() {
    // your code goes here
    int n; 
    cin>>n;
    string s;
    cin>>s;
    vector<string>ans;
    rec(0,s,"", ans);
    sort(ans.begin(), ans.end());

   for(auto it : ans){
    cout<<it<<"\n";
   }
    return 0;
}