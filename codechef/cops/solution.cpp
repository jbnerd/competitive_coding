/*
    Author: jbnerd
    Problem: https://www.codechef.com/problems/COPS
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> readHouseNumbers(int m) {
    vector<int> houseNumbers;
    houseNumbers.resize(m);
    for(int i = 0; i < m; i++) {
        cin >> houseNumbers[i];
    }
    return houseNumbers;
}

vector<int> markReachableFromHouse(vector<int> isReachable, int houseNumber, int reach) {
    int minHouseNumber = max(0, houseNumber - reach - 1);
    int maxHouseNumber = min(99, houseNumber + reach - 1);
    for(int i = minHouseNumber; i <= maxHouseNumber; i++) {
        isReachable[i] = 1;
    }
    return isReachable;
}

vector<int> markAllReachable(vector<int>& houseNumbers, int reach) {
    vector<int> isReachable(100, 0);
    for(int houseNumber : houseNumbers) {
        isReachable = markReachableFromHouse(isReachable, houseNumber, reach);
    }
    return isReachable;
}

int countUnreachable(vector<int>& houseNumbers, int reach) {
    vector<int> isReachable = markAllReachable(houseNumbers, reach);
    int sum = 0;
    for(int houseNumber : isReachable) {
        if(houseNumber == 0)
            sum += 1;
    }
    return sum;
}

int main() {

    int numTestCases;
    cin >> numTestCases;
    while(numTestCases--) {

        int m, x, y;
        cin >> m;
        cin >> x;
        cin >> y;
        vector<int> houseNumbers = readHouseNumbers(m);
        cout << countUnreachable(houseNumbers, x*y) << endl;
    }

    return 0;
}