/*
    Author: jbnerd
    Problem: http://codeforces.com/contest/5/problem/C
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int max_substr_len = 0, partial_substr_len = 0, total_substrs = 0;

void count_subseqs(vector<int>& subseq_start){
    int iter = subseq_start.size() - 1;
    while(iter >= 0){
        if(subseq_start[iter] == -1)
            iter--;
        else{
            while(subseq_start[iter] != -1 && iter != -1){
                int start = subseq_start[iter];
                partial_substr_len += iter - start + 1;
                iter = start - 1;
            }

            if(max_substr_len == partial_substr_len)
                total_substrs++;
            else if(max_substr_len < partial_substr_len){
                max_substr_len = partial_substr_len;
                total_substrs = 1;
            }

            partial_substr_len = 0;
        }
    }
}

int main(){
    string sequence;
    cin >> sequence;
    stack<int> s;
    vector<int> subseq_start(sequence.size(), -1);
    
    
    for(int i = 0; i < sequence.size(); i++)
        if(sequence[i] == '(')
            s.push(i);
        else
            if(!s.empty()){
                subseq_start[i] = s.top();
                s.pop();
            }

    count_subseqs(subseq_start);

    if(total_substrs == 0)
        cout << "0 1" << endl;
    else
        cout << max_substr_len << " " << total_substrs << endl;
}
