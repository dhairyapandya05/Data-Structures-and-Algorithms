#define MOD 1000000007
class Solution{
  public:
    void solve(int idx,string& s,set<string>& st,string& temp){
        if(idx>=s.length()){
            st.insert(temp);
            return;
        }
        //include exclude
        temp.push_back(s[idx]);
        solve(idx+1,s,st,temp);
        temp.pop_back();
        solve(idx+1,s,st,temp);
    }
	int distinctSubsequences(string s)
	{
	    set<string>st;
	    string temp=""; 
	    solve(0,s,st,temp);
	    return st.size()%MOD;
	}
};
// link:https://www.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1