#include<bits/stdc++.h>
using namespace std;
int factorial(int n){
    if(n==1){
        return 1;
    }
    return factorial(n-1)*n;
}
int main(){
    int n;
    cin>>n;
    int r;
    cin>>r;
    int m;
    cin>>m;
    int ans=(factorial(n)/(factorial(r)*factorial(n-r)))%m;
    cout<<ans;
    return 0;
}