#include<iostream>
using namespace std;
// void swap(int &a, int &b){
//     int temp = a;
//     a = b;
//     b = temp;
// }
/*
void moveAllNega(int arr[], int n){
    int low = 0, high = n-1;
    while(low < high){
        if(arr[low] < 0){
            low++;
        } else if(arr[high] > 0){
            high--;
        } else {
            swap(arr[low], arr[high]);
        }
    }
}
*/
void moveAllNega(int arr[], int left, int right){
    while(left <= right){
        if(arr[left] < 0 && arr[right] < 0){
            left++;
        } else if(arr[left] > 0 && arr[right] < 0){
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        } else if(arr[left] > 0 && arr[right] > 0){
            right--;
        } else {
            left++;
            right--;
        }
    }
}
int main(){

    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = 9;
    moveAllNega(arr, 0, n-1);
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}