//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) {
        // input.push(x);
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        output.push(x);
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
    }

    int dequeue() {
        if(input.empty()){
            return -1;
        }
        int temp=input.top();
        input.pop();
        return temp;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        }
    cout<<endl;
    }
}

// } Driver Code Ends

//T.C : push - O(1), pop - Amortized O(1) , peek() - O(1), empty() - O(1)
//S.C : O(n)
// class MyQueue {
//     private Stack<Integer> input;
//     private Stack<Integer> output;
//     private int peekEl;

//     public MyQueue() {
//         input = new Stack<>();
//         output = new Stack<>();
//         peekEl = -1;
//     }

//     public void push(int x) {
//         if (input.empty()) {
//             peekEl = x;
//         }
//         input.push(x);
//     }

//     // Amortized O(1)
//     public int pop() {
//         if (output.empty()) {
//             // Transfer elements from input to output (O(n))
//             while (!input.empty()) {
//                 output.push(input.pop());
//             }
//         }

//         int val = output.pop();
//         return val;
//     }

//     public int peek() {
//         if (output.empty()) {
//             return peekEl;
//         }

//         return output.peek();
//     }

//     public boolean empty() {
//         return input.empty() && output.empty();
//     }
// }

// https://www.geeksforgeeks.org/problems/queue-using-stack/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article