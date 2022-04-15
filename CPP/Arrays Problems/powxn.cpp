#include<bits/stdc++.h>
using namespace std;
/* Brute Force
Time Complexity -> O(n)
Space Complexity -> O(1)
*/
/*
int powxTon(double x, int n){
    double ans = 1.0;
    for(int i =0; i<n; i++){
        ans *= x;
    }
    return ans;
}
*/
/* Better Approach
Time Complexity -> O(logn)
Space Complexity -> O(1)
*/
double powxTon(double x, int n){
    double ans = 1.0;
    long long nn = n;
    if(nn < 0) nn = -1 * nn;
    while(nn){
        if(nn % 2){
            ans *= x;
            nn--;
        } else {
            x *= x;
            nn /= 2;
        }
    }
    if(n < 0) ans = (double)(1.0) / (double)(ans);
    return ans;
}

int main(){

    cout << powxTon(2, 10) << endl;

    return 0;
}