#include<bits/stdc++.h>
using namespace std;
auto cmp=[&](pair<int,int>& p1,pair<int,int>& p2){
    if(p1.first==p2.first){
        return p1.second>p2.second;
    }
    return p1.first<p2.first;
};
int solve(int n,vector<int>& power, vector<int>& bonous,int initpoints){
    vector<pair<int,int>> powerBonous;
    for(int i=0;i<power.size();i++){
        powerBonous.push_back({power[i],bonous[i]});
    }   
    sort(powerBonous.begin(),powerBonous.end(),cmp);
    int i=0;
    while(i<n and initpoints>=powerBonous[i].first){
        initpoints+=powerBonous[i].second;
        i++;
    }
    return i;
}
int main(){
    int n;
    cin>>n;
    int initpoints;
    cin>>initpoints;
    vector<int>power(n);
    vector<int>bonous(n);
    for(int i=0;i<n;i++){
        int pow;
        cin>>pow;
        power[i]=pow;
    }
    for(int i=0;i<n;i++){
        int bon;
        cin>>bon;
        bonous[i]=bon;
    }
    int ans=solve(n,power,bonous,initpoints);
    cout<<ans;

    return 0;
}
