class Solution{
public:
    stack<int> insertAtBottom(stack<int>& st,int element){
        if(st.empty()){
            st.push(element);
            return st;
        }
        int tempele=st.top();
        st.pop();
        insertAtBottom(st,element);
        st.push(tempele);
        return st;
    }
};