class StockSpanner {
public:
    stack<pair<int,int>> st;
    int i=1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty() &&st.top().first<=price){
            st.pop();
        }
        int res=st.empty()?i:i-st.top().second; // find the first one greater than you that came before you
        st.push(make_pair(price,i));
        i++;
        
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
