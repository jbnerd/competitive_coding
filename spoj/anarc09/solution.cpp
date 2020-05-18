/*
    Author: jbnerd
    Problem: https://www.spoj.com/problems/ANARC09A/
*/

#include <iostream>
#include <stack>

using namespace std;

int main(){
    string data;
    cin >> data;
    int testcase_num = 1;

    while(data[0] != '-'){
        stack<char> s;
        int counter = 0;
        for(char c : data){
            if(c == '{')
                s.push(c);
            else
                if(s.empty()){
                    counter++;
                    s.push('{');
                }else
                    s.pop();
        }

        while(!s.empty()){
            counter++;
            s.pop(); s.pop();
        }

        cout << testcase_num << ". " << counter << endl;
        cin >> data;
        testcase_num++;
    }
}