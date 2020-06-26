/*
    Author: jbnerd
    Problem: https://www.codechef.com/problems/NOKIA
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<pair<int, int>, int> max_memo;
map<pair<int, int>, int> min_memo;

pair<int, int> count(int left, int right){
    if(max_memo.find(make_pair(left, right)) != max_memo.end())
        return make_pair(max_memo[make_pair(left, right)], min_memo[make_pair(left, right)]);
    
    if(left + 1 == right){
        max_memo.insert({make_pair(left, right), 0});
        min_memo.insert({make_pair(left, right), 0});
        return make_pair(0, 0);
    }

    pair<int, int> score;
    unsigned int local_max_score = 0, local_min_score = -1;
    for(int i = left + 1; i < right; i++){
        score.first = score.second = right - left;
        pair<int, int> left_score = count(left, i);
        if(left_score == make_pair(-1, -1)) continue;
        else{
            score.first += left_score.first;
            score.second += left_score.second;
        }
        pair<int, int> right_score = count(i, right);
        if(right_score == make_pair(-1, -1)) continue;
        else{
            score.first += right_score.first;
            score.second += right_score.second;
        }
        local_max_score = max(local_max_score, (unsigned int)score.first);
        local_min_score = min(local_min_score, (unsigned int)score.second);
    }

    max_memo.insert({make_pair(left, right), local_max_score});
    min_memo.insert({make_pair(left, right), local_min_score});
    return make_pair(local_max_score, local_min_score);
}

int main(){

    int num_test_cases;
    cin >> num_test_cases;
    count(0, 31);
    while(num_test_cases--){
        int N, M;
        cin >> N;
        cin >> M;

        if(M < min_memo[make_pair(0, N+1)])
            cout << -1 << endl;
        else if(M <= max_memo[make_pair(0, N+1)])
            cout << 0 << endl;
        else
            cout << (M - max_memo[make_pair(0, N+1)]) << endl;
    }

    return 0;
}
