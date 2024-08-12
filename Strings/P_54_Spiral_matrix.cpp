class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row_count=matrix.size();
        int column_count=matrix[0].size();
        int total_element_count = row_count*column_count;
        vector<int> ans;
        int start_row=0;
        int start_col=0;
        int end_row=row_count-1;
        int end_col=column_count-1;
        int elementcount=0;
        while(elementcount < total_element_count){
            // print starting row
            for(int i=start_col;i<=end_col && elementcount<total_element_count;i++){
                elementcount++;
                ans.push_back(matrix[start_row][i]);
            }
            start_row++;
            //print ending column
            for(int i=start_row;i<=end_row && elementcount<total_element_count;i++){
                elementcount++;
                ans.push_back(matrix[i][end_col]);
            }
            end_col--;
            // print ending row
            for(int i=end_col;i>=start_col && elementcount<total_element_count;i--){
                elementcount++;
                ans.push_back(matrix[end_row][i]);
            }
            end_row--;
            // print starting colmn
            for(int i=end_row;i>=start_row && elementcount<total_element_count;i--){
                elementcount++;
                ans.push_back(matrix[i][start_col]);
            }
            start_col++;
        }

        return ans;

    }
};