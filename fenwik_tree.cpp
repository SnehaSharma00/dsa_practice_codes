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
*/
#include <iostream>
#include <vector>
using namespace std;

int pre(int index, vector<int>&fenwick){//to find prefsum of index
    int ans = 0;
    while(index>0){
        ans = ans + fenwick[index];
        index-= (index&- index);// to find rightmost 1s position
    } 
    return ans;
}

void update(int index, int val , vector<int>&fenwik){
    int n = fenwik.size();
    while(index<=n){
        fenwik[index] += val;
        index += 2^(index &- index);
    }
}