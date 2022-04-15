#include<bits/stdc++.h>
using namespace std;
//Brute Force 
/*
class Solution{
public:
vector<vector<int>> fourSum(vector<int> &nums, int target){
    int n = nums.size();

    sort(nums.begin(), nums.end());

    set<vector<int>> store;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                int x = (long long)target - (long long)nums[i] - (long long)nums[j] - (long long)nums[k];

                if(binary_search(nums.begin() + k + 1, nums.end(), x)){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    v.push_back(x);
                    sort(v.begin(), v.end());
                    store.insert(v);
                }
            }
        }
    }
    vector<vector<int>> result(store.begin(), store.end());
    return result;
} 
};
*/
//Better Approach
class Solution{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target){
        vector<vector<int>> res;

        if(nums.empty()) return res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){

            int target_3 = target - nums[i];

            for(int j = i+1; j < n; j++){
                int target_2 = target_3 - nums[j];
                int left = j + 1, right = n - 1;

                while(left < right){
                    int two_sum = nums[left] + nums[right];
                    if(two_sum < target_2) left++;
                    else if(two_sum > target_2) right--;
                    else {
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[left];
                        quadruplet[3] = nums[right];
                        res.push_back(quadruplet);

                        while(left < right && nums[left] == quadruplet[2]) left++;

                        while(left < right && nums[right] == quadruplet[3]) right--;
                    }
                }
                while(j + 1 < n && nums[j+1] == nums[j]) j++;
            }
            while(i + 1 < n && nums[i+1] == nums[i]) i++;
        }
        return res;
    }
};
int main(){

    Solution obj;
    vector<int> v{1, 0, -1, 0, -2, 2};
    vector<vector<int>> sum = obj.fourSum(v, 0);
    cout << "The unique Quadruplets are:"<< endl;
    for(int i = 0; i < sum.size(); i++){
        for(int j = 0; j < sum[i].size(); j++){
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}