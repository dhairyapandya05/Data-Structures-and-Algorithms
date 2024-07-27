void rearrange(stack<int>& st,int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    if(st.top()<element){
        st.push(element);
        return;
    }
    int temp=st.top();
    st.pop();
    rearrange(st,element);
    st.push(temp);
}

void solve(stack<int>& st){
    if(st.empty()){
        return;
    }
    int temp=st.top();
    st.pop();
    solve(st);
    rearrange(st,temp);
}
void SortedStack :: sort()
{
   solve(s);
}