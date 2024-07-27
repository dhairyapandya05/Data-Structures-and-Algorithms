class Solution
{
    public:
        void constructLPS(vector<int>& LPS,string& pat){
            LPS[0]=0;
            int length=0;
            int i=1;
            int m=pat.length();
            while(i<m){
                if(pat[i]==pat[length]){
                    length++;
                    LPS[i]=length;
                    i++;
                }
                else{
                    if(length!=0)
                        length=LPS[length-1];
                    else{
                        LPS[i]=0;
                        i++;
                    }
                }
            }
        }
        vector <int> search(string pat, string txt)
        {
            //code here
            int i=0,j=0;
            int n=txt.length();
            int m=pat.length();
            vector<int> result;
            vector<int> LPS(m,0);
            constructLPS(LPS,pat);
            while(i<n){
                if(txt[i]==pat[j]){
                    i++;
                    j++;
                }
                if(j==m){
                    result.push_back(i-j+1);
                    j=LPS[j-1];
                }
                else if(i<n and txt[i]!=pat[j]){
                    if(j!=0){
                        j=LPS[j-1];
                    }
                    else{
                        i++;
                    }
                }
            }
            return result;
        }
     
};