/*
    Author: jbnerd
    Problem: https://www.codechef.com/problems/FRGTNLNG
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> read_dictionary(int n) {
    vector<string> dictionary;
    dictionary.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> dictionary[i];
    }
    return dictionary;
}

vector<string> read_phrase(int l) {
    vector<string> phrase;
    phrase.resize(l);
    for(int i = 0; i < l; i++) {
        cin >> phrase[i];
    }
    return phrase;
}

vector<vector<string>> read_phrases(int k) {
    vector<vector<string>> phrases;
    phrases.resize(k);
    int l;
    for(int i = 0; i < k; i++) {
        cin >> l;
        phrases[i] = read_phrase(l);
    }

    return phrases;
}

void isPresent(vector<string> dictionary, vector<vector<string>> phrases){
    for(int dict_iter = 0; dict_iter < dictionary.size(); dict_iter++){
        bool flag = false;
        for(int phrase_iter = 0; phrase_iter < phrases.size(); phrase_iter++){
            for(int token_iter = 0; token_iter < phrases[phrase_iter].size(); token_iter++){
                if(dictionary[dict_iter] == phrases[phrase_iter][token_iter]){
                    flag = true;
                    break;
                }
            }

            if(flag)
                break;
        }
        if(flag)
            printf("YES ");
        else
            printf("NO ");
    }
    printf("\n");
}

int main(){

    int num_test_cases;
    scanf("%d", &num_test_cases);
    while(num_test_cases--){
        int N, K;
        scanf("%d", &N);
        scanf("%d", &K);
        vector<string> dictionary = read_dictionary(N);
        vector<vector<string>> phrases = read_phrases(K);
        isPresent(dictionary, phrases);
    }

    return 0;
}