class Solution {
public:
        int fibonacci(int n){
        // space optimisation approach
        //base case

        int previous2=0;
        int previous1=1;
        int curr;
        if(n==0)
        return previous2;
        if(n==1)
        return previous1;


        for(int i=2;i<=n;i++){
            curr= previous2+previous1;
            previous2=previous1;
            previous1=curr;
        }
        return curr;
    }
    int fib(int n) {
        return fibonacci(n);
        
    }
};