/* i/p -> arr[5] = {1, 2, 7, 8, 5} AND {1, 2, 3, 4, 5, 6} AND {1, 3, 2, 7, 11, 8}
   o/p -> arr[5] = {2, 1, 8, 7, 5} AND {2, 1, 4, 3, 6, 5} AND {3, 1, 7, 2, 8, 11}
*/
#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<< arr[i] << " ";
    }cout<<endl;
}

void swapAlternate(int arr[], int size){
    for(int i=0; i<size; i+=2){
        if(i+1 < size){
            swap(arr[i], arr[i+1]);
        }
    }
}

int main(){

    int even[] = {5, 2, 9, 4, 7, 6, 1, 0};
    int odd[] = {11, 33, 9, 75, 43};

    swapAlternate(even, 8);
    printArray(even, 8);
    cout<<endl;
    swapAlternate(odd, 5);
    printArray(odd, 5);
    return 0;
}