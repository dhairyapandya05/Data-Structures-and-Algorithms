class Solution {
public:
    string reverseParentheses(string str) {
        stack<int> st;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') {
                st.push(i);
            } else if (str[i] == ')') {
                if (!st.empty()) {
                    int idx = st.top();
                    st.pop();

                    reverse(str.begin() + idx + 1, str.begin() + i);
                    str.erase(idx, 1);
                    str.erase(i - 1, 1);
                    i-=2;
                } else {
                    return "-12";
                }
            } else {
                continue;
            }
        }

        return st.empty() ? str : "-1";
    }
};