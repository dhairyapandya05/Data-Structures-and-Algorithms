class Solution {
public:
    int solve(int i,int level,int& n,vector<vector<int>>& triangle){
        if(level>=n){
            return 0;
        }
        int ithIndex=solve(i,level+1,n,triangle)+triangle[level][i];
        int inextthIndex=INT_MAX;
        if(i+1<triangle[level].size())
        inextthIndex=solve(i+1,level+1,n,triangle)+triangle[level][i+1];
        return min(ithIndex,inextthIndex);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int idx=0,n=triangle.size();
        int ans=solve(idx,0,n,triangle);
        return ans;
    }
};