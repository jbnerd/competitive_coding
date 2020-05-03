/*
    Author: jbnerd
    Problem: https://www.spoj.com/problems/MMASS/
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int atomic_mass(char atom){
    if(atom == 'H')
        return 1;
    else if(atom == 'C')
        return 12;
    else if (atom == 'O')
        return 16;
    else
        return 0;
}

int group_mass(string formula){
    stack<int> util_stack;
    util_stack.push(0);
    int iter = 0;
    while(iter < formula.size()){
        if(isalpha(formula[iter])){
            util_stack.top() += atomic_mass(formula[iter]);
        }else if(isdigit(formula[iter])){
            util_stack.top() += (formula[iter] - '0' - 1) * atomic_mass(formula[iter-1]);
        }else if(formula[iter] == '('){
            util_stack.push(0);
        }else if(formula[iter] == ')'){
            if(isdigit(formula[iter+1])){
                util_stack.top() *= formula[iter+1] - '0';
                iter++;
            }
            int temp_mass = util_stack.top();
            util_stack.pop();
            util_stack.top() += temp_mass;
        }
        iter++;
    }

    return util_stack.top();
}

int main(){

    string formula;
    cin >> formula;
    stack<char> parse_stack;
    int iter = 0;
    cout << group_mass(formula) << endl;

    return 0;
}