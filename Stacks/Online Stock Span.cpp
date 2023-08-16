https://leetcode.com/problems/online-stock-span/description/

class StockSpanner {
public:
    stack<pair<int, int>>st;
    int ind = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first <= price) st.pop();

        int ans;
        if(!st.empty()) ans = ind - st.top().second;
        else ans = ind-(-1);

        st.push({price, ind});
        ind++;
        return ans;
    
    }
};


