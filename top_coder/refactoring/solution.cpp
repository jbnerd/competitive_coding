/*
    Author: jbnerd
    Problem: https://community.topcoder.com/stat?c=problem_statement&pm=4475&rd=8012
*/

#include <iostream>

using namespace std;

class Refactoring{
    public:
        int refactor(int n);
    
    private:
        int count(int n, int last);
};

int Refactoring::refactor(int n){
    return count(n, 2);
}

int Refactoring::count(int n, int last){
    int ret = 0;
    for (int i=last; i*i<=n; i++)
        if (n % i == 0)
	        ret += 1 + count(n/i, i);
    return ret;
}

int main(){

    Refactoring test = Refactoring();
    int n;
    cin >> n;
    cout << test.refactor(n) << endl;

    return 0;
}