#include <bits/stdc++.h>
using namespace std;

long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        long long int sum=accumulate(skill.begin(),skill.end(),0LL);
        int numberTeam=(n/2);
        int teamcontribution=sum/numberTeam;
        if(sum%numberTeam==1){
            cout<<"This is the palce of error "<<endl;
            return -1;
        }
        sort(skill.begin(),skill.end());
        int i=0;
        int j=n-1;
        int team=0;
        long long ans=0;
        while(i<j){
            if(skill[i]+skill[j]==teamcontribution){
                ans+=(skill[i]*skill[j]);
                i++;
                j--;
                team++;
                cout<<endl<<"Ans: "+ans<<endl;
            }
            
            else{
                return -1;
            }
            
        }
        return ans;
    }
int main()
{
    vector<int> skill = {3,4};
    
    long long int ans = dividePlayers(skill);
    cout << endl
         << "Answer: " << ans;
    return 0;
}