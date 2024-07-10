class Solution {
  public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long toh(int n, int from, int to, int aux) {
        // Your code here
        if(n==0){
            return 0;
        }
        if(n==1){
            cout<<"move disk "<<n << " from rod " <<from<< " to rod " <<to<<endl;
            return 1;
        }
        long long int count=toh(n-1,from,aux,to);
        count+=1;
        cout<<"move disk "<<n<< " from rod "<< from  <<" to rod " <<to<<endl;
        count+=toh(n-1,aux,to,from);
        return count;
    }
};