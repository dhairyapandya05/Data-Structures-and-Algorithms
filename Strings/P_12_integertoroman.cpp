class Solution {
public:
    string intToRoman(int num) {
        string rm[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int values[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string ans;
        for(int i=0;i < 13;i++){
            while(num >= values[i]){
                // ans.push_back(rm[i]);
                //remember that pushback is ued in place of a character small adding at the end of a already string
                //whereas ans+=ans+value[i] is used to concadinate another string with the original string

                ans+=rm[i];
                num-=values[i];
            }
        }
        return ans;
    }
};