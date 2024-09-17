#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& arr,int n){
    int even=0;
    int odd=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            even++;
        }
        else{
            odd++;
        }
    }
    return odd-even;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    int ans=solve(arr,n);
    cout<<ans;
    return 0;
}