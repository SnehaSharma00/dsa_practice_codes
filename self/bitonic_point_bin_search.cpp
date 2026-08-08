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




