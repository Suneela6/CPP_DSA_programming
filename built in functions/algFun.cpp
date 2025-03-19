#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
   int arr[]={4,2,3,9,1}; 
   int n=sizeof(arr)/sizeof(arr[0]);
   sort(arr,arr+n);
   cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
   bool found=binary_search(arr,arr+n,3);
   cout << "Is 3 present in the array? " << (found ? "Yes" : "No") << endl;
   reverse(arr,arr+n);
   cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
   auto it=find(arr,arr+n,2);
   if (it != arr + n)
        cout << "Element 2 found at index: " << (it - arr) << endl;
    else
        cout << "Element 2 not found in the array." << endl;
   int count_2=count(arr,arr+n,2);
   cout << "Count of 2 in the array: " << count_2 << endl;
} 