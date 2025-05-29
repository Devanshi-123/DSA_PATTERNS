// https://leetcode.com/problems/insert-delete-getrandom-o1/submissions/1608121128/

class RandomizedSet {
    public:
        unordered_set<int>st;
        RandomizedSet() {
            
        }
        
        bool insert(int val) {
            if(st.find(val) != st.end()){
                return false;
            }
            st.insert(val);
            return true;
        }
        
        bool remove(int val) {
             if(st.find(val) != st.end()){
                st.erase(val);
                return true;
            }
            return false;
        }
        
        int getRandom() {
            // convert the random num,ber to a list 
            int n = st.size();
            vector<int>vec;
    
            for(auto it = st.begin(); it != st.end(); it++){
                vec.push_back(*it);
            }
            // find a random index 
            int rndIdx = rand()%n;
            // return the elem at that index 
            return vec[rndIdx];
        }
    };