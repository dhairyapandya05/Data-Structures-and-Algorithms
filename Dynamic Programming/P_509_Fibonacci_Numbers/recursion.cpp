class Solution {
public:
    int fibonacci(int n){
        //base case
        if(n<2){
            return n;
        }
        return fibonacci(n-1)+fibonacci(n-2);
    }
    int fib(int n) {
        return fibonacci(n);
        
    }
};