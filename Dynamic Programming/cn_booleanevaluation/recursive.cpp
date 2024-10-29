#include <bits/stdc++.h>
int const mod =1000000007;
typedef long long ll;
ll solve(int i, int j,string & exp, int isTrue) {
    if (i > j) {
        return 0;
    }
    if (i == j) {
        if (isTrue) {
            return exp[i]=='T';
        } else 
            return exp[i]=='F';
    }
    ll ways=0;
    for (int idx = i + 1; idx <= j - 1; idx += 2) {
        ll lT=solve(i,idx-1,exp,1);
        ll lF=solve(i,idx-1,exp,0);
        ll rT=solve(idx+1,j,exp,1);
        ll rF=solve(idx+1,j,exp,0);

        if (exp[idx] == '&') {
            if(isTrue){
                ways=(ways+(lT*rT)%mod)%mod;
            }else{
                ways=(ways+(((lF*rF)%mod+(lF*rT)%mod)%mod+(lT*rF)%mod)%mod)%mod;
                // F F 
                // T F
                // F T
            }
        }
        else if(exp[idx]=='|'){
            if(isTrue){
                ways=(ways+(((lT*rT)%mod+(lF*rT)%mod)%mod+(lT*rF)%mod)%mod)%mod;
            }
            else{
                ways=(ways+(lF*rF)%mod)%mod;
            }
        }
        else{
            // xor condition
            // T-> T F , F T
            // F-> T T , F F
            if(isTrue){
                ways=(ways+((lT*rF)%mod+(lF*rT)%mod)%mod)%mod;
            }
            else{
                ways=(ways+((lT*rT)%mod+(lF*rF)%mod)%mod)%mod;
            }
        }
    }
    return ways;
}
int evaluateExp(string & exp) {
    // Write your code here.
    int n=exp.length();
    return solve(0,n-1,exp,1)%mod;
}