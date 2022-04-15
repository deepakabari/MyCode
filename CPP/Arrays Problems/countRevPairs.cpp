#include<bits/stdc++.h>
using namespace std;
//Brute Force:
//T.C.->O(n^2), S.C.->O(1)
/*
int reversePairs(vector<int> &arr){
    int pairs = 0;
    for(int i = 0; i<arr.size(); i++){
        for(int j = i+1; j<arr.size(); j++){
            if(arr[i] > 2*arr[j]) pairs++;
        }
    }
    return pairs;
}
*/
//Better Approach:
//T.C.->O(nlogn)+O(n)+O(n) where O(nlogn) for mergeSort, O(n) for merge operation, O(n) for counting Operation
//S.C.->O(n)->temporary vector
int merge(vector<int> &nums, int low, int mid, int high){
    int total = 0;
    int j = mid + 1;
    for(int i = low; i<=mid; i++){
        while (j <= high && nums[i] > 2 * nums[j]){
            j++;
        }
        total += (j - (mid+1));
    }
    vector<int> ans;
    int left = low, right = mid + 1;
    while(left <= mid && right <= high){
        if(nums[left] <= nums[right]){
            ans.push_back(nums[left++]);
        } else {
            ans.push_back(nums[right++]);
        }
    }
    while(left <= mid)
        ans.push_back(nums[left++]);
    while(right <= high)
        ans.push_back(nums[right++]);
    for(int i = low; i <= high; i++){
        nums[i] = ans[i - low];
    }
    return total;
}
int mergeSort(vector<int> &nums, int low, int high){
    if(low >= high) return 0;
    int mid = (low+high)/2;
    int inv = mergeSort(nums, low, mid);
    inv += mergeSort(nums, mid+1, high);
    inv += merge(nums, low, mid, high);
    return inv;
}
int reversePairs(vector<int> &arr){
    return mergeSort(arr, 0, arr.size()-1);
}

int main(){

    vector<int> arr{40, 19, 25, 12, 9, 6, 2};
    cout << "Total numbers of Pairs: " << reversePairs(arr);

    return 0;
}