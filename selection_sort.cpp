#include<iostream>
using namespace std;

void selection_sort(int arr[],int n){
	for(int pos = 0; pos <= n-2; pos++){
		int current = arr[pos];
		int min_position = pos;
		for(int j=pos; j<n; j++){
			if(arr[j] < arr[min_position]){
				min_position = j;
			}
		}
		swap(arr[min_position],arr[pos]);
	}
}


int main(){
    int arr[]={-2,3,4,-1,5,-12,6,1,9};
    int n = sizeof(arr)/sizeof(int);
    selection_sort(arr,n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}