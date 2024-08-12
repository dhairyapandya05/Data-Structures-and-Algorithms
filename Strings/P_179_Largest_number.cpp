class Solution {
public:

    static bool cmp(string a,string b){
        string t1=a+b;
        string t2=b+a;
        return t1 > t2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> str_num;
        for(auto n:nums){
            str_num.push_back(to_string(n));
        }
        // now the integers are converted into strings and now they are ready to be sorted
        sort(str_num.begin(),str_num.end(),cmp);
        if(str_num[0]=="0") return "0";
        string ans;
        for(auto str:str_num){
            ans+=str;
        }
        return ans;
    }
};