#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& arr,int pos,int& n){
    int sum=0;
    while(pos<n){
        sum+=abs(arr[pos]-arr[pos-1]);
        pos++;
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    int pos;
    cin>>pos;
    int ans=solve(arr,pos,n);
    cout<<ans;
    return 0;
}