/*
    Author: jbnerd
    Problem: https://www.codechef.com/problems/LAPIN
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void populate_freq(vector<int>& freq, string S, int start, int end){
    for(int i = start; i < end; i++)
        freq[S[i] - 'a']++;
}

bool compare_freqs(vector<int>& freq1, vector<int>& freq2){
    bool flag = true;
    for(int i = 0; i < 26; i++){
        if(freq1[i] != freq2[i]){
            flag = false;
            break;
        }
    }
    return flag;
}

int main(){
    int numTestCases;
    cin >> numTestCases;
    while(numTestCases--){
        string S;
        cin >> S;
        int halfPoint, len = S.size();
        if(len % 2 == 0)
            halfPoint = len / 2;
        else
            halfPoint = (len + 1) / 2;

        vector<int> freq1, freq2;
        freq1.resize(26);
        freq2.resize(26);
        populate_freq(freq1, S, 0, halfPoint);
        if (len % 2 == 0)
            populate_freq(freq2, S, halfPoint, len);
        else
            populate_freq(freq2, S, halfPoint - 1, len);

        if(compare_freqs(freq1, freq2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}