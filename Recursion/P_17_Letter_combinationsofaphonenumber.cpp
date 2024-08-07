class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }

        int index=0;
        string output="";
        vector<string> mapping(10);
        mapping[2]="abc";
        mapping[3]="def";
        mapping[4]="ghi";
        mapping[5]="jkl";
        mapping[6]="mno";
        mapping[7]="pqrs";
        mapping[8]="tuv";
        mapping[9]="wxyz";
        solve(ans,index,output,digits,mapping);
        return ans;
    }

    void solve(vector<string>&ans,int index,string &output,string digits,vector<string>&mapping){
        // ..base case
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }

        // case1 solve karna hai baki recursion sambhal laega
        char digit=digits[index];
        int digitInt=digit-'0';
        string value=mapping[digitInt];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            char ch=value[i];
            // int newIndex=++index;
            // string newoutput=output+ch;
            solve(ans,index+1,output,digits,mapping);
            output.pop_back();

        }

    }
};