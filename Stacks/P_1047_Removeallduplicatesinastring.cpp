class Solution {
public:
    stack<char> st;
    string removeDuplicates(string s) {
        for (int i = 0; i < s.length(); i++) {

            if (!st.empty() and s[i] == st.top()) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        string str = "";
        while (!st.empty()) {
            str = st.top() + str;
            st.pop();
        }

        return str;
    }
};