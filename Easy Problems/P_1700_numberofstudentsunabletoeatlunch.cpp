class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int s_0 = 0;
        int s_1 = 0;
        int n = students.size();
        for (int i = 0; i < students.size(); i++) {
            if (students[i] == 1) {
                s_1++;
            } else if (students[i] == 0) {
                s_0++;
            }
        }
        for (int i = 0; i < sandwiches.size(); i++) {
            if (sandwiches[i] == 1) {
                if (s_1 == 0) {
                    return n - i;
                }
                s_1--;
            } else if (sandwiches[i] == 0) {
                if (s_0 == 0) {
                    return n - i;
                }
                s_0--;
            }
        }
        return 0;
    }
};