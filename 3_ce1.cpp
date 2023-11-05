// Implement a function that takes array of integers as input and returns the largest element.

// Sample Input

// -3 4 1 2 3

// -1 -2 -3 -3 8

// Sample Output

// 4

// 8

#include<iostream>
using namespace std;

void largestElement(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(arr[0]<arr[i])
        {
            arr[0]=arr[i];
        }
    }
    cout<<arr[0]<<endl;
}
void inputElement(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
}

int main()
{   int n = 5;
    int arr[5];
    
    inputElement(arr,n);
    largestElement(arr, n);

    return 0;
}
