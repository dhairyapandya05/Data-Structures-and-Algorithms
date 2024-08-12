int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    // min [max(A[i],B[j],C[k])-min(A[i],B[j],C[k]) ]
    int i=0,j=0,k=0;
    int mini=INT_MAX;
    while(i<A.size() and j<B.size() and k<C.size()){
        int minValue = min({A[i], B[j], C[k]});
        int maxValue = max({A[i], B[j], C[k]});
        int diff = maxValue - minValue;//I will have to incerease the minValue to decrease the difference created
        mini=min(mini,diff);
        if (minValue == A[i]) {
            i++;
        } else if (minValue == B[j]) {
            j++;
        } else {
            k++;
        }
        
    }
    return mini;
}
