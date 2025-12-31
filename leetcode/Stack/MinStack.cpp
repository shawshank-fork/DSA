
#include <stack>
using namespace std;

class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val >= mini) {
                st.push(val);
            } else {
                st.push(2LL * val - mini);
                mini = val;
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long top = st.top();
        st.pop();

        if (top < mini) {
            mini = 2LL * mini - top;
        }

        if (st.empty()) mini = LLONG_MAX;
    }

    int top() {
        if (st.empty()) return -1;

        long long top = st.top();
        if (top >= mini) return top;
        else return mini;
    }

    int getMin() {
        return mini;
    }
};