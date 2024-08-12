int missingK(vector < int > vec, int n, int k) {
    // Write your code here.
    int s=0,e=n-1;
    while (s <= e) {
        int m=s+(e-s)/2;
        int missing=vec[m]-(m+1);


        if (missing >= k) {
            e=m-1;
        }
        else {
            s=m+1;
        }
    }
    // at this point
    // s=e+1;
    return k+s;
}
// important testcase dry run on this imp
// 9
// 1 2 3 4 5 6 7 8 10 
// 1


// Normal method
int missingK(vector < int > vec, int n, int k) {
    // Write your code here.
    for (auto it : vec) {
      if (it <= k) {
          k++;
      } else {
          break;
      }
    }
    return k;
}