#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>

//Minimum bit flips such that every K consecutive bits contain at least one set bit

int consecutive(string bitspilani, int k) {
    int flips = 0;
    int zeros = 0;


    for(auto ch : bitspilani) {
        if(ch == '0'){
            zeros++;

            if(zeros == k){
                flips++;
                zeros = 0;
            }
        }
        else {
            zeros = 0;
        }
    }
    return flips;
}