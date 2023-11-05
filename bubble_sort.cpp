#include<iostream>
using namespace std;

void bubble_sort(int arr[],int n){
    for(int times = 1; times<=n-1; times++){
        for(int j = 0; j < n - times - 1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[]={-2,3,4,-1,5,-12,6,1,9};
    int n = sizeof(arr)/sizeof(int);
    bubble_sort(arr,n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}