#include<iostream>
using namespace std;

int reverseArray(int arr[], int n)
{
    int s = 0;
    int e = n - 1;

    while(s<e)
    {
        swap(arr[s],arr[e]);
        s+=1;
        e-=1;
    }
}

int main()
{
    int arr[]={10,20,30,45,60,80,90};
    int n  = sizeof(arr)/sizeof(int);

    //printing the array initially
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    reverseArray(arr,n);

    //printing the array after reversing
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
