class Solution{
    public:
    bool isSafe(int i,int j,vector<vector<bool>> &visited,vector<vector<int>> &maze,int& n){
        if(i>=0 and i<n and j>=0 and j<n and visited[i][j]==0 and maze[i][j]==1){
            return true;
        }
        return false;
    }
    void solve(int i,int j,vector<vector<bool>> &visited,vector<vector<int>> &maze,int& n,vector<string>& ans,string& temp){
        if(i==n-1 and j==n-1){
            ans.push_back(temp);
        }
        if(isSafe(i+1,j,visited,maze,n)){
            temp.push_back('D');
            visited[i+1][j]=true;
            solve(i+1,j,visited,maze,n,ans,temp);
            temp.pop_back();
            visited[i+1][j]=false;
        }
        if(isSafe(i,j+1,visited,maze,n)){
            temp.push_back('R');
            visited[i][j+1]=true;
            solve(i,j+1,visited,maze,n,ans,temp);
            temp.pop_back();
            visited[i][j+1]=false;
        }
        if(isSafe(i-1,j,visited,maze,n)){
            temp.push_back('U');
            visited[i-1][j]=true;
            solve(i-1,j,visited,maze,n,ans,temp);
            temp.pop_back();
            visited[i-1][j]=false;
        }
        if(isSafe(i,j-1,visited,maze,n)){
            temp.push_back('L');
            visited[i][j-1]=true;
            solve(i,j-1,visited,maze,n,ans,temp);
            temp.pop_back();
            visited[i][j-1]=false;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0){
            return {"-1"};
        }
        vector<vector<bool>> visited(n,vector<bool> (n,0));
        visited[0][0]=1;
        vector<string> ans;
        string temp="";
        solve(0,0,visited,m,n,ans,temp);
        return ans;
    }
};