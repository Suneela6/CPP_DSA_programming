#include<iostream>
using namespace std;
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        if (minindex != i) {
            swap(arr[i], arr[minindex]);
        }
    }
} 
int main() {
    int arr[] = {13, 46, 24, 52, 20, 9}; 
    int n = sizeof(arr) / sizeof(arr[0]); 

    selectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}