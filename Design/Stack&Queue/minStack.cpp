// https://leetcode.com/problems/min-stack/

// used a stack of pair to store the curr and the min value
// we will use the first element of the pair to store the curr value and the second element to store the min value

// Time : O(1)
// Space : O(n)

class MinStack {
    public:
        stack<pair<int,int>>st;
        MinStack() {
           
        }
        
        void push(int val) {
            if(st.empty()){
                st.push({val,val});
            }else {
                st.push({val, min(val, st.top().second)});
            }
        }
        
        void pop() {
            st.pop();
        }
        
        int top() {
            if(st.empty()){
                return -1;
            }
    
            return st.top().first;
        }
        
        int getMin() {
            if(st.empty()){
                return -1;
            }
            return st.top().second;
        }
    };
    