/*sliding window 

Diverse Words Count
Difficulty: MEDIUM | Max Score: 50
You are given a string consisting of only three types of characters: "X", "Y", and "Z".

Your task is to count the number of substrings that contain at least one occurrence of all three characters ("X", "Y", and "Z").



Input Format:

A single string s of length at least 3, consisting only of the characters "X", "Y", and "Z".


Output Format:

A single integer representing the number of substrings that contain at least one occurrence of all three characters.


Constraints:

3 ≤ s.length ≤ 5 × 104
s consists only of the characters "X", "Y", and "Z".


Examples 1:

Input
XYZXYZ

Output
10

Explanation:
The valid substrings that contain at least one "X", "Y", and "Z" are:
"XYZ"
"XYZX"
"XYZXY"
"XYZXYZ"
"YZX"
"YZXZ"
"YZXZY"
"ZXZ"
"ZXZY"
"XYZ" (again)
Thus, there are 10 valid substrings.


Example 2:

Input:
XXXYZ

Output:
3

Explanation:
The valid substrings are:
"XXXYZ"
"XXYZ"
"XYZ"
Thus, there are 3 valid substrings.


Example 3:

Input:
XYZ

Output:
1

Explanation:
The only valid substring is "XYZ" itself.
*/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    string s; 
    cin>>s;
    //vector<int>freq;
    int n = s.size();
    long long l=0 , r=0;
    int freq[3]={0};
    freq[s[0]-'X']++;
    long long ans = 0;

//total operations = 2n , tc = O(n)
    while(r<n){

        while(l < r && freq[0]>0 && freq[1]>0 && freq[2]>0){
            freq[s[l]-'X']--;
                l++;
                ans += (n-r);
            }
            r++;
            if(r<n) freq[s[r] - 'X']++;
        }
    cout<<ans;
    return 0;
}