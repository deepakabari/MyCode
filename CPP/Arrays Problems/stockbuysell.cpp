#include<bits/stdc++.h>
using namespace std;

/*
int maxProfit(int arr[], int n) {
  int maxPro = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j] > arr[i]) {
        maxPro = max(arr[j] - arr[i], maxPro);
      }
    }
  }
  return maxPro;
}
*/
int maxProfit(int arr[], int n) {
  int maxPro = 0;
  int minPrice = INT_MAX;
  for (int i = 0; i < n; i++) {
      minPrice = min(minPrice, arr[i]);

      maxPro = max(maxPro, arr[i] - minPrice);
  }
  return maxPro;
}

int main() {

  int n;
  cin >> n;
  int arr[n];
  for(int i=0; i<n; i++){
      cin >> arr[i];
  }
  int maxPro = maxProfit(arr, n);
  cout << "Max profit is: " << maxPro << endl;
}