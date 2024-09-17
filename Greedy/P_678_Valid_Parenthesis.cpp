class Solution {
public:
    bool checkValidString(string s) {
        int min=0;
        int max=0;
        for(auto it:s){
            if(it=='('){
                min++;
                max++;
            }
            else if(it==')'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }
            if(max<0){
                return false;
            }
            if(min<0){
                min=0;
            }
        }
        return (min==0);
    }
};