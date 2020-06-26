/*
    Author: jbnerd
    Problem: https://www.codechef.com/problems/TRISQ
*/

#include <iostream>

using namespace std;

int count(int b){
    if(b <= 2){
        return 0;
    }else{
        return (b - 2) / 2 + count(b - 2);
    }
}

int main(){

    int num_test_cases;
    cin >> num_test_cases;
    while(num_test_cases--){
        int b;
        cin >> b;
        cout << count(b) << endl;
    }

    return 0;
}