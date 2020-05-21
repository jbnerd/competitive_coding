/*
    Author: jbnerd
    Problem: http://codeforces.com/contest/797/problem/C
*/


#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> freqs(26, 0);

void count_frequencies(const string& data){
    for(char c : data)
        freqs[c - 'a'] += 1;
}

int next_available_char_index(){
    for(int i = 0; i < freqs.size(); i++)
        if(freqs[i] != 0)
            return i;
    return -1;
}

vector<char> rearrange(const string& data){
    vector<char> rearranged(data.size());
    int iter = 0;
    stack<char> s;
    for(char c : data){
        s.push(c);
        freqs[c - 'a']--;
        int chr_idx = next_available_char_index();
        while(!s.empty() && freqs[chr_idx] != 0 && s.top() <= chr_idx + 'a'){
            rearranged[iter++] = s.top();
            s.pop();
        }
    }

    while(!s.empty()){
        rearranged[iter++] = s.top();
        s.pop();
    }

    return rearranged;
}

int main(){
    string data;
    cin >> data;
    
    count_frequencies(data);
    vector<char> rearranged = rearrange(data);
    for(char c: rearranged)
        cout << c;
    cout << endl;

    return 0;
}