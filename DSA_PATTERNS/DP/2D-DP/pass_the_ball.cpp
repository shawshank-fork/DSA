#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>

// question - there are N people, suppose person 2 has the ball to start with.
// He can pass the ball to other n - 1 people but in the end the ball must comeback to person 2 i.e the initail person who started the game
//but there a some conditions 
// 1. There are can be only M maximum passes to get the ball back to the person who started
// 2. one person can pass the ball to the other person only if person i divides person j or vise versa
// we have to return the number of ways we can accomplish this
// we are given 3 inputs, input 1 - number of people, input 2 - the person from which the game starts, input 3 - number of maxium passes allowed

int ways(int input1, int input2, int input3) {

    int n = input1;
    int m = input3;
    int start = input2;
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0)); // dp[people][moves] it states the ways we can get ball back when we have i people and j moves

    dp[start][0] = 1;
}