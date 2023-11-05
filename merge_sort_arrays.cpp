#include<iostream>
using namespace std;

void merge(int arr[], int s, int mid, int e){
    int n1 = mid-s+1;
    int n2 = e-mid;
    int a[n1];
    int b[n2];

    for(int i = 0; i < n1; i++){
        a[i]=arr[mid+i];
    }
    for(int i = 0; i < n2; i++){
        b[i]=arr[mid+1+i];
    }

    int i = 0, j = 0, k = s;
    while(i<s && j<e){
        if(a[i]<b[j]){
            arr[k]=a[i];
            i++;
            k++;
        }
        else{
            arr[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
            i++;
            k++;
    }
    while(j<n2){
        arr[k]=b[j];
            j++;
            k++;
    }
}

void merge_sort(int arr[], int s, int e){
    //base case
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    merge_sort(arr,s,mid);
    merge_sort(arr,mid+1,e);
    merge(arr,s,mid,e);
}

int main(){
     int arr[]={-2,3,4,-1,5,-12,6,1,9};
    int n = sizeof(arr)/sizeof(int);
    merge_sort(arr,0,8);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}