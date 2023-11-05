#include<iostream>
using namespace std;

int binary_search(int arr[], int n, int key) // here is it very important to include [] in the declaration of arr
{
    int s = 0;
    int e = n-1; // n-1 is the index of the last element of the array

    while(s<e)
    {
        int m = (s+e)/2;
        if(arr[m]==key)
        {
            return m;
        }
        else if(arr[m]<key)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[]={10,20,30,40,45,60,70,89};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cin>>key;

    int index = binary_search(arr,n,key);
    if(index!=-1)
    {
        cout<<key<<" is present at index "<<index<<endl;
    }
    else
    {
        cout<<key<<" is NOT found ! "<<endl;
    }

    return 0;
}