class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for (auto& it : details) {
            string phoneno = it.substr(0, 10);
            string gender = it.substr(10, 1);
            int age = stoi(it.substr(11, 2));
            if (age > 60) {
                cnt++;
            }
        }
        return cnt;
    }
};