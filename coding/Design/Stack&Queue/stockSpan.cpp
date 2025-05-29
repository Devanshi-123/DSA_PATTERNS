// https://leetcode.com/problems/online-stock-span/description/?envType=company&envId=google&favoriteSlug=google-thirty-days

// Time complexity: O(1) for next
// Space complexity: O(n) for storing the prices

class StockSpanner {
    public:
        stack<pair<int,int>>s;
        StockSpanner() {
            
        }
        
        int next(int price) {
            int count = 1;
            if (s.size() > 0 && s.top().first <= price){
                while(s.size() > 0 && s.top().first <= price) {
                    count += s.top().second;
                    s.pop();
                }
            }
            s.push({price,count});
            return count;
        }
    };
    
    /**
     * Your StockSpanner object will be instantiated and called as such:
     * StockSpanner* obj = new StockSpanner();
     * int param_1 = obj->next(price);
     */