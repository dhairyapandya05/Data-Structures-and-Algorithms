class StockSpanner {
public:
stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        while(!st.empty() && st.top().second <=price){
            span=span+st.top().first;
            st.pop();
        }
        st.push({span,price});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// My method
class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {}

    int next(int price) {
        int span = 1;
        if (st.empty()) {
            st.push({price, span});
            return 1;
        } else {
            while(!st.empty() and st.top().first <=price){
                span+=st.top().second;
                st.pop();
            }
            st.push({price, span});
            return span;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */