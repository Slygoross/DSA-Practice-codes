#include<iostream>
#include"stackLL.h"
using namespace std;

int main(){
    Stack<char> s;
    s.push('v');
    s.push('a');
    s.push('n');
    s.push('a');
    s.push('r');
    s.push('p');
    s.display();
    return 0;
}