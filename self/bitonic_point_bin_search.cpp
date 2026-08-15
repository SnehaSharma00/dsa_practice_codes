/*Bitonic Point
Difficulty: EasyAccuracy: 58.67%Submissions: 237K+Points: 2Average Time: 15m
Given an array of integers arr[] that is first strictly increasing and then maybe strictly decreasing, find the bitonic point, that is the maximum element in the array.
Bitonic Point is a point before which elements are strictly increasing and after which elements are strictly decreasing.

Note: It is guaranteed that the array contains exactly one bitonic point.

Examples:

Input: arr[] = [1, 2, 4, 5, 7, 8, 3]
Output: 8
Explanation: Elements before 8 are strictly increasing [1, 2, 4, 5, 7] and elements after 8 are strictly decreasing [3].
Input: arr[] = [10, 20, 30, 40, 50]
Output: 50
Explanation: Elements before 50 are strictly increasing [10, 20, 30 40] and there are no elements after 50.
Input: arr[] = [120, 100, 80, 20, 0]
Output: 120
Explanation: There are no elements before 120 and elements after 120 are strictly decreasing [100, 80, 20, 0].
Constraints:

3 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 106
*/




#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);  // how to hardcode array
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int l= 0, h = arr.size()-1;

    while(l<h){
        int mid = l + (h-l) /2; // why to do this 

        if(arr[mid] > arr[mid -1] && arr[mid] < arr[mid+1]){
            l = mid +1;
        }
        else if(arr[mid] < arr[mid-1] && arr[mid] > arr[mid+1]){
            h = mid -1;
        }
    }

    cout<<arr[l]<<endl;  //why l and why not h 

}




