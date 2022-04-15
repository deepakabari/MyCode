#include<bits/stdc++.h>
using namespace std;
/*
Brute Force Approach
Time Complexity -> O(nlogn + n)
Space Complexity -> O(1)
*/
/*
int findDuplicate(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end()); //O(nlogn)
    for(int i=0; i<n-1; i++){     //O(n)
        if(arr[i] == arr[i+1]){
            return arr[i];
        }
    }
}
*/
/* 
Better Approach
Time Complexity -> O(n)
Space Complexity -> O(n)
*/
/*
int findDuplicate(vector<int> &arr){
    int n = arr.size();
    int freq[n+1] = {
        0
    };
    for(int i=0; i<n; i++){
        if(freq[arr[i]] == 0){
            freq[arr[i]] += 1;
        } else {
            return arr[i];
        }
    }
    return 0;
}
*/
/* Optimal Approach
Time Complexity -> O(n)
Space Complexity -> O(1)
*/
int findDuplicate(vector<int> &arr){
    int slow = arr[0], fast = arr[0];
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow != fast);
    fast = arr[0];
    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}


int main(){

    vector<int> arr;
    arr = {1, 3, 4, 2, 2};
    cout << "Duplicate Number is: " << findDuplicate(arr) << endl;

    return 0;
}