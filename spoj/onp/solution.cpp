/*
    Author: jbnerd
    Problem: https://www.spoj.com/problems/ONP/
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    int num_test_cases;
    cin >> num_test_cases;
    while(num_test_cases--){
        string infix_notation, postfix_notation;
        cin >> infix_notation;
        stack<char> operators;
        for(auto &c: infix_notation){
            if(c == '('){
                continue;
            }else if(c >= 'a' && c <= 'z'){
                postfix_notation += c;
            }else if(c == ')'){
                postfix_notation += operators.top();
                operators.pop();
            }else{
                operators.push(c);
            }
        }

        cout << postfix_notation << endl;
    }

    return 0;
}