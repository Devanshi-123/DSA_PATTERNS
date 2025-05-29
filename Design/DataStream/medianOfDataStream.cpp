// https://leetcode.com/problems/find-median-from-data-stream/

// Using max heap and min heap
// Time complexity: O(log n) for addNum
// Space complexity: O(n) for storing the numbers

class MedianFinder {
    public:
        // maxheap to store first half 
        priority_queue<int>mxHp;
        priority_queue<int, vector<int>, greater<int>>minHp;
        MedianFinder() {
            
        }
        
        void addNum(int num) {
            if(mxHp.empty() || num < mxHp.top()){
                mxHp.push(num);
            }else {
                minHp.push(num);
            }
    
            // balance 
            while(mxHp.size() > minHp.size()+1){
                minHp.push(mxHp.top());
                mxHp.pop();
            }
            while(minHp.size() > mxHp.size()){
                mxHp.push(minHp.top());
                minHp.pop();
            }
        }
        
        double findMedian() {
            if(mxHp.size() > minHp.size()){
                return mxHp.top();
            }else {
                return (mxHp.top() + minHp.top())/2.0;
            }
        }
    };