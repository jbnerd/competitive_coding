/*
    Author: jbnerd
    Problem: http://codeforces.com/contest/343/problem/B
*/

#include <iostream>
#include <stack>

using namespace std;

int main(){
    string wires;
    cin >> wires;
    stack<char> s;
    for(char c : wires)
        if(s.empty() || s.top() != c)
            s.push(c);
        else
            s.pop();
        
    if(s.empty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}