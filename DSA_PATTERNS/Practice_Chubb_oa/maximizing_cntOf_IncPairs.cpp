#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>

// int numberOfPairs(vector<int>& a1, vector<int>& a2) {
//     int n1 = a1.size();
//     int n2 = a2.size();
//     vector<int> visited(n2, 0);
//     int count = 0;

//     for(int i = 0; i < n1; i++) {
        
//         for(int j = 0; j < n2; j++){
//             if((visited[j] == 0) && (2*a1[i] <= a2[j])) {
//                 count++;
//                 visited[j] = 1;
//                 break;
//             }
//         }
//     }
//     return count;
// }


int numberofPairs(vector<int> &a1, vector<int> &a2) {
    int n = a1.size();
    int n2 = a2.size();
    int count = 0;
    
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());

    int i = 0;
    int j = 0;

    while(i < n && j < n2) {

        if(2 * a1[i] <= a2[j]){
            count++;
            i++;
            j++;
        }

        else {
            j++;
        }
    }
    return count;
    
}    