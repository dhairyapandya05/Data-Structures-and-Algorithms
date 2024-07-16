class Solution {
public:
    typedef unordered_map<string, int> mp;
    string countOfAtoms(string formula) {
        int i = 0;
        int n = formula.length();
        stack<mp> st;
        st.push(mp());
        while (i < n) {
            if (formula[i] == '(') {
                st.push(mp());
                i++;
            } else if (formula[i] == ')') {
                mp curr = st.top();
                st.pop();
                string multiplier = "";
                i++;
                while (i < n and isdigit(formula[i])) {
                    multiplier += formula[i];
                    i++;
                }
                if (!multiplier.empty()) {
                    int intmultiplier = stoi(multiplier);
                    for (auto& [atom, count] : curr) {
                        curr[atom] = count * intmultiplier;
                    }
                }
                for (auto& [atom, count] : curr) {
                    st.top()[atom] += count;
                }
            } else {
                string currentAtom;
                currentAtom += formula[i];
                i++;
                while (i < n and islower(formula[i])) {
                    currentAtom += formula[i];
                    i++;
                }

                string currcount;
                while (i < n and isdigit(formula[i])) {
                    currcount += formula[i];
                    i++;
                }
                int count = (currcount.empty()) ? 1 : stoi(currcount);
                st.top()[currentAtom] += count;
            }
        }
        // by now we would be having only one map in the stack only one element
        // in the stack
        mp unsorted = st.top();
        st.pop();
        map<string, int> sortMap(begin(unsorted), end(unsorted));
        string finalans;
        for (auto& [atom, count] : sortMap) {
            finalans += atom;
            if (count > 1) {
                finalans += to_string(count);
            }
        }
        return finalans;
    }
};