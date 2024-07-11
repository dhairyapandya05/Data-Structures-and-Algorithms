class Solution{
	public:
	    void solve(int idx,string& s, string& temp,vector<string>& ans){
	        if(idx>=s.length()){
	            if(!temp.empty())
	            
	            ans.push_back(temp);
	            return;
	        }
	        // include a substring
	        temp.push_back(s[idx]);
	        solve(idx+1,s,temp,ans);
	        temp.pop_back();
	        //exclude a substirng
	        solve(idx+1,s,temp,ans);


	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int idx=0;
		    vector<string> ans;
		    string temp="";
		    solve(idx,s,temp,ans);

		  sort(ans.begin(),ans.end());
		    return ans;
		}
};