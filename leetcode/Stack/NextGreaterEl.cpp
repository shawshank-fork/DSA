#include <stack>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;


class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            stack<int> st;
            unordered_map<int, int> ngeMap;
    
            for (int i = nums2.size() - 1; i >= 0; --i) {
                while (!st.empty() && st.top() <= nums2[i]) {
                    st.pop();
                }
                int nextGreater = st.empty() ? -1 : st.top();
                ngeMap[nums2[i]] = nextGreater;
                st.push(nums2[i]);
            }
    
            vector<int> result;
            for (int num : nums1) {
                result.push_back(ngeMap[num]);
            }
            return result;
        }
    };
    