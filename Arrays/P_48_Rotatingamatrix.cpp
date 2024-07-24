class Solution {
public:
    void rotate(vector<vector<int>>& arr) {

        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr[i].size(); ++j)
                swap(arr[i][j], arr[j][i]);
        }
        for (int i = 0; i < arr.size(); i++) {
            reverse(arr[i].begin(), arr[i].end());
        }
    }
};
// 3 2 1
// 6 5 4
// 9 8 7


// 1 4 7
// 2 5 8
// 3 6 9
// [[3,6,9],[2,5,8],[1,4,7]]
// [[7,4,1],[8,5,2],[9,6,3]]