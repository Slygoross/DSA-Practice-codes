#include<iostream>
using namespace std;

int partition(int arr[],int s, int e){
    int pivot = arr[e];
    int i = s - 1;
    for(int j = s; j < e; j++){
        if(pivot>arr[j]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}

void quick_sort(int arr[], int s, int e){
    int p = partition(arr,s,e);
    quick_sort(arr,s,p);
    quick_sort(arr,p+1,e);
}

int main(){
    int arr[]={-2,3,4,-1,5,-12,6,1,9};
    int n = sizeof(arr)/sizeof(int);
    quick_sort(arr,0,8);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}