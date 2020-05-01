/*
    Author: jbnerd
    Problem: https://www.codechef.com/problems/CSUB
*/

#include <iostream>
#include <string>

using namespace std;

long long countOnes(string& bin) {
    long long sum = 0;
    for(char bit : bin) {
        if(bit == '1')
            sum += 1;
    }
    return sum;
}

long long countValidSubStrings(string& bin) {
    long long numOnes = countOnes(bin);
    return (numOnes)*(numOnes+1)/2;
}

int main() {

    int numTestCases;
    cin >> numTestCases;
    while(numTestCases--) {

        int n;
        cin >> n;
        string bin;
        cin >> bin;
        cout << countValidSubStrings(bin) << endl;
    }

    return 0;
}