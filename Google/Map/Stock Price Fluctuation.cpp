
https://leetcode.com/problems/stock-price-fluctuation/description/

class StockPrice {
public:
    unordered_map<int ,int>mp;
    multiset<int>prices;
    int last_timestamp = 0;

    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(mp.find(timestamp) != mp.end()){
            prices.erase(prices.find(mp[timestamp]));
        }

        if(timestamp > last_timestamp) last_timestamp = timestamp;
        prices.insert(price);
        mp[timestamp] = price;
    }
    
    int current() {
        return mp[last_timestamp];
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
};
