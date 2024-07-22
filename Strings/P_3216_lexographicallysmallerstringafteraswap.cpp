class Solution {
public:
    string getSmallestString(string s) {
        int n=s.length();
        for(int i=0,j=1;i<n-1;){
            int a=stoi(to_string(s[i]));
            int b=stoi(to_string(s[j]));
            if(a%2==b%2 and b<a ){
                swap(s[i],s[j]);
                break;
            }
            else{
                i++;
                j++;
            }
        }
        return s;
    }
};