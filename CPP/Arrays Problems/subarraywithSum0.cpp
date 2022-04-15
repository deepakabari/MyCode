#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//T.C.->O(N^2), S.C.->O(1)
/*
int solve(int a[], int n){
    int large = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++){
            sum += a[j];
            if(sum == 0){
                large = max(large, (j-i+1));
            }
        }
    }
    return large;
}
*/
//Optimal Approach
//T.C.->O(N), S.C.->O(N)
int solve(int arr[], int n){
    unordered_map<int, int> map;
    int maxi = 0, sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
        if(sum == 0) maxi = i + 1;
        else {
            if(map.find(sum) != map.end()){
                maxi = max(maxi, i - map[sum]);
            } else {
                map[sum] = i;
            }
        }
    } 
    return maxi;
}
int main(){
    int arr[] = {6, -2, 2, -8, 1, 7, 4, -10}; 
    cout << solve(arr, 8) << endl;
    return 0;
}
