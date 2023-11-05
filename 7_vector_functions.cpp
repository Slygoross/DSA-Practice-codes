#include<iostream>
using namespace std;

class vector{
    private:
    int cs, ms;
    int *arr;
    public:
    vector()
    {
        cs = 0;
        ms = 1;
        arr = new int[ms];
    }

    void push_back(int d)
    {
        if(cs==ms)
        {
            // create a new array of double size
            int *oldarr = arr;
            ms = 2*ms;
            arr = new int[ms];
            // Copy the elements
            for(int i = 0; i < cs; i++)
            {
                arr[i] = oldarr[i];
            }
            // Delete the old one
            delete [] oldarr;
        }

        arr[cs] = d;
        cs++;
    }

    void pop_back()
    {
        if(cs>=0)
        {
            cs--;
        }
    }

    bool isempty()
    {
        return cs==0;
    }

    // A const function is that function which doesnt modify the data members of the class
    int front()
    const{
        return arr[0];
    }

    int back()
    const{
        return arr[cs-1];
    }

    int at(int i)
    const{
        return arr[i];
    }

    int size()
    const{
        return cs;        
    }

    int capacity()
    const{
        return ms;
    }

    int operator[](const int i)
    {
        return arr[i];
    }
};

int main()
{
    vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.pop_back();

    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    cout<<v.at(2)<<endl;

    return 0;
}