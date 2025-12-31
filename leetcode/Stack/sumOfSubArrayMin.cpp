#include <stack>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

class Solution {
    public:
        vector<int> findnse(vector<int>& arr) {
            int n = arr.size();
            vector<int> nse(n, n); // default to n
            stack<int> st;
    
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && arr[st.top()] >= arr[i]) {
                    st.pop();
                }
                if (!st.empty()) {
                    nse[i] = st.top();
                }
                st.push(i);
            }
            return nse;
        }
    
        vector<int> findpse(vector<int>& arr) {
            int n = arr.size();
            vector<int> pse(n, -1);
            stack<int> st;
    
            for (int i = 0; i < n; i++) {
                while (!st.empty() && arr[st.top()] > arr[i]) {
                    st.pop();
                }
                if (!st.empty()) {
                    pse[i] = st.top();
                }
                st.push(i);
            }
            return pse;
        }
    
        int sumSubarrayMins(vector<int>& arr) {
            int n = arr.size();
            vector<int> nse = findnse(arr);
            vector<int> pse = findpse(arr);
            int mod = 1e9 + 7;
            long long total = 0;
    
            for (int i = 0; i < n; i++) {
                long long l = i - pse[i];
                long long r = nse[i] - i;
    
                total = (total + ((l * r) % mod * arr[i]) % mod) % mod;
            }
            return total;
        }
    };
    