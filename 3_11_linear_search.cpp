#include<iostream>
using namespace std;

int linear_search(int arr[], int n, int key)
{
    for(int i=0;i<n;i++)
    {
        // Here we are checking if the current element matches the key
        if(arr[i]==key)
        {
            return i;
        }
    }

    return -1;
}
int main()
{
    int arr[] = {2,56,4,32,78,56,43,26};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cout<<"Enter the Key Element you wish to find: "<<endl;
    cin>>key;

    int index = linear_search(arr,n,key);
    if(index!=-1)
    {
        cout<<key<<" was found at index "<<index+1<<endl;
    }
    else
    {
        cout<<key<<" is not found!"<<endl;
    }

    return 0;
}