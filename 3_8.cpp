#include<iostream>
using namespace std;

int main()
{
    int marks[100];
    int n;
    cout<<"Enter the No. of students: "<<endl;
    cin>>n;
    //input
    for(int i=0;i<n;i++)
    {
        cin>>marks[i];
        cout<<endl;
    }
    //Output
    for(int i=0;i<n;i++)
    {
        cout<<"The Marks of student "<<i+1<<" is: "<<marks[i]<<endl;
    }

    return 0;

}