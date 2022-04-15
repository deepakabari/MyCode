#include<bits/stdc++.h>
using namespace std;

int kadane(int arr[], int n){
    int currentSum = 0;
    int maxSum = INT_MIN;
    for(int i = 0; i < n; i++){
        currentSum += arr[i];
        if(currentSum < 0) currentSum = 0;
        maxSum = max(maxSum, currentSum);
    }   
    return maxSum;
}


int main(){

    int arr[] = {1,2,3,-2,5};
    int n = 5;
    cout << kadane(arr, n) << endl;

    return 0;
}
