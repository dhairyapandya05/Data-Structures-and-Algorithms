class Solution {
public:
    bool deletethecandidate(string& senate, int idx, char ch) {
        int n = senate.length();
        bool check = false;
        while (true) {
            if (idx == 0) {
                check = true;
            }
            if (senate[idx] == ch) {
                senate.erase(senate.begin() + idx);
                break;
            }
            idx = (idx + 1) % senate.length();
        }
        return check;
    }
    string predictPartyVictory(string senate) {
        int n = senate.length();
        int Rcnt = count(senate.begin(), senate.end(), 'R');
        int Dcnt = n - Rcnt;
        int i = 0;
        while (Rcnt > 0 and Dcnt > 0) {
            if (i >= senate.length()) {
                i = 0;
            }
            if (senate[i] == 'R') {
                bool checkbackflag =
                    deletethecandidate(senate, (i + 1) % senate.length(), 'D');
                Dcnt--;
                if (checkbackflag) {
                    i--;
                }
            } else {
                bool checkbackflag =
                    deletethecandidate(senate, (i + 1) % senate.length(), 'R');
                Rcnt--;
                if (checkbackflag) {
                    i--;
                }
            }
            i = (i + 1) % senate.length();
        }
        if (Rcnt == 0) {
            return "Dire";
        }
        return "Radiant";
    }
};