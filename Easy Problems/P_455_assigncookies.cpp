class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int childrencnt=g.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cookieindex=0;
        int childindex=0;
        int ans=0;
        for(;childindex<childrencnt and cookieindex<s.size();){
            if(g[childindex] <=s[cookieindex]){
                ans++;
                childindex++;
                cookieindex++;
            }
            else{
                cookieindex++;
            }
        }
        return ans;
    }
};