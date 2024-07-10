class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="./"){
                continue;
            }
            else if(logs[i]=="../"){
                if(ans<=0){
                    continue;
                }
                ans--;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};