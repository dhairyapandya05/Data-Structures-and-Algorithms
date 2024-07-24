class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1);
        stringstream ss2(version2);
        string token1 = "";
        string token2 = "";
        while (ss1.good() or ss2.good()) {
            if (!getline(ss1, token1, '.'))
                token1 = "0";
            if (!getline(ss2, token2, '.'))
                token2 = "0";
            if (stoi(token1) > stoi(token2)) {
                return 1;
            } else if (stoi(token1) < stoi(token2)) {
                return -1;
            }
        }
        return 0;
    }
};