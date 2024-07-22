class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int solve(int n, int& x, int& y, int& z){
        if(n<=0){
            return 0;
        }
        int a=solve(n-x,x,y,z);
        int b=solve(n-y,x,y,z);
        int c=solve(n-z,x,y,z);
        return max({a,b,c})+1;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int ans=solve(n,x,y,z);
        return ans;
    }
};