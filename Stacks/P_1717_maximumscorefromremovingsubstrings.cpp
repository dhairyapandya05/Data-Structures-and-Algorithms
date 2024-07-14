class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        string tosearch = (x > y) ? "ab" : "ba";
        int value = (x > y) ? x : y;
        int count = 0;
        for (auto& it : s) {
            if (tosearch[1] == it && !st.empty() && st.top() == tosearch[0]) {
                st.pop();
                count += value;
            } else {
                st.push(it);
            }
        }

        // Now check for the other part
        if (st.empty()) {
            return count;
        } else {
            int othervalue = x + y - value;
            int temp = st.top();
            st.pop();
            while (!st.empty()) {
                if (temp == tosearch[0]) {
                    if (st.top() == tosearch[1]) {
                        count += othervalue;
                    }
                }

                if (!st.empty()) {
                    temp = st.top();
                    st.pop();
                } else {
                    break;
                }
            }
        }
        return count;
    }
};