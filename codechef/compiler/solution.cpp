/*
    Author: jbnerd
    Problem: https://www.codechef.com/problems/COMPILER
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    int num_test_cases;
    cin >> num_test_cases;
    while(num_test_cases--){
        string line;
        cin >> line;
        stack<char> util_stack;
        int partial_len = 0, total_len = 0;
        for(auto &chr: line){
            if(chr == '<'){
                util_stack.push('<');
            }else if(chr == '>' && !util_stack.empty()){
                partial_len += 2;
                util_stack.pop();
                if(util_stack.empty()){
                    total_len += partial_len;
                    partial_len = 0;
                }
            }else{
                break;
            }
        }

        cout << total_len << endl;
    }

    return 0;
}
