/*
    Author: jbnerd
    Problem: http://codeforces.com/problemset/problem/281/D

    Commentary:
        With a monotonic stack we are able to maintain the left just largest and the right just largest
        element for every element in a list. We leverage this fact to extract the largest and the second
        largest elements in a given sub-sequence for computing the maximum xor.

        For an element at i with left just largest element at li and right just largest element at ri, 
        the largest and second largest element pairs in sub-sequences [li, i], [i, ri] and [li, ri] are
        respectively [seq[li], seq[i]], [seq[ri], seq[i]], [seq[li], seq[ri]] or [seq[ri], seq[li]].
*/

#include <iostream>
#include <stack>
#include <vector>

#define lli long long int

using namespace std;

vector<lli> read_seq(int n){
    vector<lli> seq(n);
    for(auto &i: seq)
        cin >> i;
    return seq;
}

int main(){

    int n;
    cin >> n;
    vector<lli> seq = read_seq(n);
    stack<int> s;

    lli max_xor = 0;
    for(int iter = 0; iter < seq.size(); iter++){
        if(s.empty() || seq[s.top()] > seq[iter]){
            s.push(iter);
        }else{
            while(!s.empty() && seq[s.top()] < seq[iter]){
                lli top_height = seq[s.top()];
                s.pop();
                int left_index = (s.empty()) ? -1 : s.top(), right_index = iter;

                if(left_index != -1) max_xor = max(max_xor, seq[left_index] ^ top_height);
                if(left_index != -1) max_xor = max(max_xor, seq[left_index] ^ seq[right_index]);
                max_xor = max(max_xor, seq[right_index] ^ top_height);
            }
            s.push(iter);
        }
    }

    while(!s.empty()){
        int top_height = seq[s.top()];
        s.pop();
        if (s.empty()) break;
        int left_index = s.top();
        max_xor = max(max_xor, seq[left_index] ^ top_height);
    }

    cout << max_xor << endl;

    return 0;
}
