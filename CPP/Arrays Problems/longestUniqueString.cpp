#include<bits/stdc++.h>
using namespace std;
//Brute Force Approach
//T.C.->O(N^2), S.C.->O(N)
/*
int solve(string str){
    int maxans = INT_MIN;
    int n = str.length();
    for(int i = 0; i < n; i++){
        unordered_set<int> set;
        for(int j = i; j < n; j++){
            if(set.find(str[j]) != set.end()){
                maxans = max(maxans, j-i);
                break;
            }
            set.insert(str[j]);
        }
    }
    return maxans;
}
*/
//Better Approach
//T.C.->O(2N), S.C.->O(N)
/*
int solve(string str){
    int maxans = INT_MIN;
    unordered_set<int> set;
    int l = 0;
    for(int r = 0; r < str.length(); r++){
        if(set.find(str[r]) != set.end()){
            while(l < r && set.find(str[r]) != set.end()){
                set.erase(str[l]);
                l++;
            }
        }
        set.insert(str[r]);
        maxans = max(maxans, r-l+1);
    }
    return maxans;
}
*/
//Optimal Approach
//T.C.->O(N), S.C.->O(N)

int solve(string str){
    vector<int> mpp(256, -1);
    int left = 0, right = 0;
    int n = str.size();
    int len = 0;
    while(right < n){
        if(mpp[str[right]] != -1){
            left = max(mpp[str[right]] + 1, left);
        }
        mpp[str[right]] = right;

        len = max(len, right - left + 1);
        right++;
    }
    return len;
}

int main(){

    string str = "takeUforward";
    cout << "The length of longest substring without repeating characters: " << solve(str) << endl;

    return 0;
}