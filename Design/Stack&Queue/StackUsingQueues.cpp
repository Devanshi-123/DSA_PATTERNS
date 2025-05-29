// https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
    public:
        // Step 1 : define all the req data structures 
        queue<int>q1;
        queue<int>q2;
    
        MyStack() {
            // Step 2 : initialise req data structure
        }
        
        void push(int x) {
            if(q1.empty()){
                q1.push(x);
                while(!q2.empty()){
                    q1.push(q2.front());
                    q2.pop();
                }
            }else {
                q2.push(x);
                while(!q1.empty()){
                    q2.push(q1.front());
                    q1.pop();
                }
            }
        }
        
        int pop() {
            int x = -1;
            if(q1.empty() && q2.empty()){
                return x;
            }
            else if(!q1.empty()){
                x = q1.front();
                q1.pop();
                return x;
            }else{
                x = q2.front();
                q2.pop();
                return x;
            }
        }
        
        int top() {
             int x = -1;
            if(q1.empty() && q2.empty()){
                return -1;
            }
            else if(!q1.empty()){
                x = q1.front();
                return x;
            }else{
                x = q2.front();
                return x;
            }
        }
        
        bool empty() {
            if(q1.empty() && q2.empty()){
                return true;
            }else {
                return false;
            }
        }
    };