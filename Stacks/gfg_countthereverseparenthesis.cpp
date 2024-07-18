int countRev (string s)
{
    // your code here
    if(s.length()%2==1){
        return -1;
    }
    stack<char> st;
    int oper=0;
    for(auto it:s){
        if(st.empty() and it=='}'){
            oper++;
            st.push('{');
            continue;
        }
        if(it=='{'){
            st.push('{');
        }
        if(it=='}'){
            if(!st.empty()){
                st.pop();
            }
        }
    }
    return oper+st.size()/2;
}