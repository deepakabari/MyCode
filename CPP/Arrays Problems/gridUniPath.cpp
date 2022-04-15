#include<bits/stdc++.h>
using namespace std;
/* Brute Force
class solution{
public:
    int countPaths(int i, int j, int n, int m){
        if(i==(n-1) && j==(m-1)) return 1;
        if(i>=n || j>=m) return 0;
        else return (countPaths(i+1, j, n, m) + countPaths(i, j+1, n, m));
    }
    int uniquePaths(int m, int n){
        return countPaths(0, 0, m, n);
    }
};
*/
//Better : Dynamic Programming
//T.C.->O(n*m), S.C.-> O(n*m)
/*
class solution{
public:
    int countPaths(int i, int j, int n, int m, vector<vector<int>> &dp){
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        else return dp[i][j] = countPaths(i+1,j,n,m,dp) + countPaths(i,j+1,n,m,dp);
    }
    int uniquePaths(int m, int n){
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int num = countPaths(0, 0, m, n, dp);
        if(m==1&&n==1) return num;
        return dp[0][0];
    }
};
*/
//Combiinatorics Solution
//T.C.-> O(n-1)orO(m-1), S.C.->O(1)
class solution
{    
public:
    int uniquePaths(int m, int n){
        int N = n + m - 2;
        int r = m - 1;
        double res = 1;

        for(int i = 1; i <= r; i++)
            res *= (N - r + i)/i;
        return (int)res;
    }
};

int main(){

    solution obj;
    int totalCount = obj.uniquePaths(3, 7);
    cout << "Total number of paths are: " << totalCount << endl;

    return 0;
}