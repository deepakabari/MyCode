#include<bits/stdc++.h>
using namespace std;

/*
Brute Force Approach
Time Complexity -> O(n*logn) + O(n) + O(n)
Space Complexity -> O(n) 
*/
/*
void merge(int arr1[], int arr2[], int n, int m){
    int arr3[m+n];
    int k = 0;
    for(int i =0; i<n; i++){
        arr3[k++] = arr1[i];
    }
    for(int i = 0; i<m; i++){
        arr3[k++] = arr2[i];
    }
    sort(arr3, arr3+m+n);
    k = 0;
    for(int i=0; i<n; i++){
        arr1[i] = arr3[k++];
    }
    for(int i=0; i<m; i++){
        arr2[i] = arr3[k++];
    }

}
*/

/* Optimal Approach 
Time Complexity -> O(n * m)
Space Compexity -> O(1)
*/
/*
void merge(int arr1[], int arr2[], int n, int m) {
  // code here
  int i, k;
  for (i = 0; i < n; i++) {
    // take first element from arr1 
    // compare it with first element of second array
    // if condition match, then swap
    if (arr1[i] > arr2[0]) {
      int temp = arr1[i];
      arr1[i] = arr2[0];
      arr2[0] = temp;
    }

    // then sort the second array
    // put the element in its correct position
    // so that next cycle can swap elements correctly
    int first = arr2[0];
    // insertion sort is used here
    for (k = 1; k < m && arr2[k] < first; k++) {
      arr2[k - 1] = arr2[k];
    }
    arr2[k - 1] = first;
  }
}
*/
/*
GAP Method
Time Complexity -> O(logn)
Space Complexity -> O(1)
*/
void merge(int arr1[], int arr2[], int n, int m){
    int gap = ceil((float)(n+m)/2);
    while(gap > 0){
        int i=0, j=gap;
        while(j < (n+m)){
            if(j < n && arr1[i] > arr1[j]){
                swap(arr1[i], arr2[j]);
            } else if(j >= n && i < n && arr1[i] > arr2[j - n]){
                swap(arr1[i], arr2[j-n]);
            } else if(j >= n && i >= n && arr2[i-n] > arr2[j-n]){
                swap(arr2[i-n], arr2[j-n]);
            }
            j++;
            i++;
        }
        if(gap == 1){
            gap = 0;
        } else {
            gap = ceil((float)(gap)/2);
        }
    }
} 
int main(){

    int arr1[] = {1, 4, 7, 8, 10};
    int arr2[] = {2, 3, 9};
    cout << "Before Merge:" << endl;
    for(int i=0; i<5; i++){
        cout << arr1[i] << " ";
    }cout << endl;
    for(int i=0; i<3; i++){
        cout << arr2[i] << " ";
    }cout << endl;
    merge(arr1, arr2, 5, 3);

    cout << "After Merge" << endl;
    for(int i=0; i<5; i++){
        cout << arr1[i] << " ";
    }cout << endl;
    for(int i=0; i<3; i++){
        cout << arr2[i] << " ";
    }
    return 0;
}