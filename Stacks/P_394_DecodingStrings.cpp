class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for (auto it : s) {
            if (it == ']') {
                string stringtorepear = "";
                while (!st.empty() and st.top() != "[") {
                    stringtorepear = st.top()+stringtorepear;
                    st.pop();
                }
                st.pop(); // to remove the [ mark
                string numeric = "";
                while (!st.empty() and isdigit(st.top()[0])) {
                    numeric = st.top()+numeric;
                    st.pop();
                }
                int number = stoi(numeric);
                string finalstring = "";
                while (number--) {
                    finalstring += stringtorepear;
                }
                st.push(finalstring);
            } else {
                st.push(string(1, it));
            }
        }
        string strf = "";
        while (!st.empty()) {
            strf = st.top()+strf;
            st.pop();
        }
        return strf;
    }
};