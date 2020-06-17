/*
    Author: jbnerd
    Problem: https://community.topcoder.com/stat?c=problem_statement&pm=3458&rd=5869
*/

#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class PrimeAnagrams{
    vector<int> curr_primes = vector<int>(3, 0);

    public:
        vector<int> primes(string anagram){
            vector<pair<int, int>> partition_indices = three_way_partitions_indices(anagram.size());
            sort(anagram.begin(), anagram.end());
            do{
                for(pair<int, int>& partition_index_pair: partition_indices){
                    vector<string> partitions = make_partitions(anagram, partition_index_pair);
                    vector<int> partitions_int = string_vec_to_int_vec(partitions);
                    if(has_not_leading_zero_all(partitions) && is_prime_partitions(partitions_int)){
                        if(curr_primes[0] == 0 || curr_primes[0] * curr_primes[1] * curr_primes[2] > partitions_int[0] * partitions_int[1] * partitions_int[2]){
                            sort(partitions_int.begin(), partitions_int.end());
                            for(int i = 0; i < partitions_int.size(); i++)
                                curr_primes[i] = partitions_int[i];
                        }
                    }
                }
            }while(next_permutation(anagram.begin(), anagram.end()));

            if(curr_primes[0] == 0){
                vector<int> empty;
                return empty;
            }else{
                return curr_primes;
            }
        }

    private:
        vector<int> string_vec_to_int_vec(vector<string>& partitions){
            vector<int> partitions_int;
            for(string partition: partitions)
                partitions_int.push_back(stoi(partition));
            return partitions_int;
        }

        vector<pair<int, int>> three_way_partitions_indices(int len){
            vector<pair<int, int>> partitions;
            for(int i = 1; i < len; i++)
                for(int j = i + 1; j < len; j++)
                    partitions.push_back(pair<int, int> (i, j));
            return partitions;
        }

        vector<string> make_partitions(string& anagram, pair<int, int>& partition_indices){
            vector<string> partitions;
            int first = partition_indices.first, second = partition_indices.second;
            partitions.push_back(anagram.substr(0, first));
            partitions.push_back(anagram.substr(first, second - first));
            partitions.push_back(anagram.substr(second, anagram.size() - second));
            return partitions;
        }

        bool has_not_leading_zero_all(vector<string>& partitions){
            bool flag = true;
            for(string partition: partitions){
                flag = (partition[0] != '0');
                if(!flag) break;
            }
            return flag;
        }

        bool is_prime_partitions(vector<int>& partitions){
            bool flag = true;
            for(int partition: partitions){
                flag = is_prime(partition);
                if(!flag) break;
            }
            return flag;
        }

        bool is_prime(long long int n){
            bool flag = true;

            if(n < 2)
                flag = false;
            else if(n == 2)
                flag = true;
            else if(n % 2 == 0)
                flag = false;
            else
                for(long long int i = 3; i <= sqrt(n); i += 2)
                    if(n % i == 0){
                        flag = false;
                        break;
                    }
        
            return flag;
        }
};

int main(){

    PrimeAnagrams anagram_test = PrimeAnagrams();
    string input;
    cin >> input;
    
    vector<int> output = anagram_test.primes(input);

    if(output.empty())
        cout << "Empty!" << endl;
    else
        cout << output[0] << " " << output[1] << " " << output[2] << endl;

    return 0;
}