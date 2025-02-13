class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int s = 0;
        int e = (m * n) - 1;
        cout << e << "it";
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            int row = mid / m;
            int col = mid % m;
            if (matrix[row][col] == target)
            {
                return true;
                break;
            }
            else if (matrix[row][col] > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return false;
    }
};