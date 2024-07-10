class Solution{
public:
    void Reverse(stack<int> &st){
        if(st.empty()==true){
            return;
        }
        int ele=st.top();
        st.pop();
        Reverse(st);
        stack<int> tempst;
        while(!st.empty()){
            int tempele=st.top();
            st.pop();
            tempst.push(tempele);
        }
        st.push(ele);
        while(!tempst.empty()){
            int tempele=tempst.top();
            tempst.pop();
            st.push(tempele);
        }
    }
};

// using full recursion space complexity O(1)

class Solution{
public:
    void insertatBottom(int element,stack<int>& st){
        if(st.empty()){
            st.push(element);
            return;
        }
        int tempele=st.top();
        st.pop();
        insertatBottom(element,st);
        st.push(tempele);
    }
    void Reverse(stack<int> &st){
        if(st.empty()==true){
            return;
        }
        int ele=st.top();
        st.pop();
        Reverse(st);
        insertatBottom(ele,st);
    }
};