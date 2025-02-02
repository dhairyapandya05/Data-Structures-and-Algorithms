class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> nums, ans;
        for (int i = 0; i < s.size(); i++) {
            string x = "";
            for (int j = i; j < s.size(); j++) {
                x += s[j];
                int num = stoi(x);
                if (low <= num && num <= high) {
                    ans.push_back(num);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Approach 2
// TC:O(n) where n is the total number of sequencial digits m

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> qe;
        vector<int> result;
        for (int i = 1; i < 9; i++) {
            qe.push(i);
        }
        while (!qe.empty()) {
            auto it = qe.front();
            qe.pop();
            if (it >= low and it <= high) {
                result.push_back(it);
            }
            int lastdigit = (it % 10);
            if (lastdigit + 1 <= 9) {
                int newNumber = (it * 10) + (lastdigit + 1);
                qe.push(newNumber);
            }
        }
        return result;
    }
};
