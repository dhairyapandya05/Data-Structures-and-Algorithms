class Solution 
{
    public:
    bool knows(vector<vector<int> >& M,int a,int b){
        return M[a][b]==1;
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()>1){
            int a=st.top();st.pop();
            int b=st.top();st.pop();
            if(knows(M,a,b)){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        int check=st.top();st.pop();
        int count=0;
        for(int i=0;i<n;i++){
            if(M[check][i]==0)
                count++;
        }
        if(count!=n){
            return -1;
        }
        count=0;
        for(int i=0;i<n;i++){
            if(M[i][check]==1)
                count++;
        }
        if(count!=n-1){
            return -1;
        }
        return check;
    }
};