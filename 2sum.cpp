#include<bits/stdc++.h>
using namespace std;
//Brute Force 
//T.C.->O(n^2), S.C.->O(1)
/*
vector<int> twosum(vector<int> &nums, int target){
    vector<int> res;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i+1; j < nums.size(); j++){
            if(nums[i] + nums[j] == target){
                res.emplace_back(i);
                res.emplace_back(j);
                break;
            }
        }
        if(res.size() == 2){
            break;
        }
    }
    return res;
}
*/
//Better Approach
//T.C.->O(nlogn), S.C.->O(n)
/*
vector<int> twosum(vector<int> &nums, int target){
    vector<int> res, store;
    store = nums;
    sort(store.begin(), store.end());
    int left = 0, right = nums.size()-1;
    int n1, n2;
    while(left < right){
        if(store[left] + store[right] == target){
            n1 = store[left];
            n2 = store[right];
            break;  
        } else if(store[left] + store[right] > target){
            right--;
        } else {
            left++;
        }
    }
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == n1)
            res.emplace_back(i);
        else if(nums[i] == n2)
            res.emplace_back(i);
    }
    return res;
}
*/
//Optimal Approach
//T.C.->O(), S.C.->O()
vector<int> twosum(vector<int> &nums, int target){
    vector<int> res;
    unordered_map<int, int>ans;
    for(int i = 0; i < nums.size(); i++){
        if(ans.find(target - nums[i]) != ans.end()){
            res.emplace_back(ans[target - nums[i]]);
            res.emplace_back(i);
            return res;
        }
        ans[nums[i]] = i;
    } 
    return res;
}
int main(){

    vector<int> arr = {2, 1, 3, 4};
    int target = 3;
    for(auto &x : twosum(arr, target))
        cout << x << " ";
    cout << endl;
    return 0;
}