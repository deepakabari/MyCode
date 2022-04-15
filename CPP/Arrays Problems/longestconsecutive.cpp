#include<bits/stdc++.h>
using namespace std;
//Brute Force
//T.C.->O(NlogN), S.C.->O(1)
/*
int longestconsecutive(vector<int> nums){
    if(nums.size() == 0) return 0;

    sort(nums.begin(), nums.end());

    int ans = 1, prev = nums[0], cur = 1;
    for(int i = 1; i<nums.size(); i++){
        if(nums[i] == prev+1) cur++;
        else if(nums[i] != prev) cur = 1;
        prev = nums[i];
        ans = max(ans, cur);                    
    }
    return ans;
}
*/
//Optimal Approach
//T.C.->O(N) bcoz we traverse each consecutive subsequence only once, 
//S.C.->O(N) bcoz we are maintaining a HashSet
int longestconsecutive(vector<int> &nums){
    set<int> hashset;
    for(int num : nums){
        hashset.insert(num);
    }
    int longestStreak = 0;
    for(int num : nums){
        if(!hashset.count(num-1)){
            int currentNum = num;
            int currentStreak = 1;

            while(hashset.count(currentNum+1)){
                currentNum++;
                currentStreak++;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}
int main(){
 
    vector<int> arr{100, 200, 1, 3, 4, 2};
    int lon = longestconsecutive(arr);
    cout << "Longest Consecutive sequence is: " << lon << endl;

    return 0;
}