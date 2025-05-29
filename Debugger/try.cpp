#include<bits/stdc++.h>

using namespace std;
bool checkValidity(unordered_map<char,pair<int,int>>& mp , char ch,int& k){
    return min(mp[ch].first,mp[ch].second)>0;
}

void printmp(unordered_map<char,pair<int,int>>& mp){
    for(auto it:mp){
        cout<<"Character: "<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl; 
    }
}

int solve(string s,int k) {
    unordered_map<char,pair<int,int>> mp;
    for(auto it:s){
        mp[it].first++;
    }
    int n=s.length();
    int count=0;
    set<char>st;
    for(int i=0;i<n-1;i++){
        mp[s[i]].first--;
        mp[s[i]].second++;
        bool valid=checkValidity(mp,s[i],k);
        // cout<<"valid:" <<valid;
        auto it=st.find(s[i]);
        if(valid and it==st.end()){
            st.insert(s[i]);
        }
        else if(!valid and it!=st.end()){
            st.erase(it);
        }
        if(st.size()>k){
            count++;
        }
        printmp(mp);
        
        for(auto it:st){
            cout<<it;
        }
        cout<<endl;
        cout<<"Count: "<<count<<endl;
        cout<<endl;
        
    }
    return count;
}

// Example usage
int main() {
    
int ans=solve("wxyzzyxw",1);
cout<<"Answer: "<<ans;
    return 0;
}
