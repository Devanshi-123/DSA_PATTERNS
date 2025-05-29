// https://leetcode.com/problems/finding-mk-average/submissions/1613611486/?envType=company&envId=google&favoriteSlug=google-thirty-days

class MKAverage {
    public:
        int m, k;
        long long midSum = 0;
        queue<int> q;
        multiset<int> low, mid, high;
    
        MKAverage(int m, int k) {
            this->m = m;
            this->k = k;
        }
    
        void addElement(int num) {
            q.push(num);
    
            if ((int)q.size() <= m) {
                mid.insert(num);
                midSum += num;
                if ((int)q.size() == m) {
                    // Initialize low and high
                    while ((int)low.size() < k) {
                        int val = *mid.begin();
                        mid.erase(mid.begin());
                        midSum -= val;
                        low.insert(val);
                    }
                    while ((int)high.size() < k) {
                        auto it = prev(mid.end());
                        int val = *it;
                        mid.erase(it);
                        midSum -= val;
                        high.insert(val);
                    }
                }
                return;
            }
    
            // Add new element
            if (num <= *low.rbegin()) {
                low.insert(num);
                int moved = *prev(low.end());
                low.erase(prev(low.end()));
                mid.insert(moved);
                midSum += moved;
            } else if (num >= *high.begin()) {
                high.insert(num);
                int moved = *high.begin();
                high.erase(high.begin());
                mid.insert(moved);
                midSum += moved;
            } else {
                mid.insert(num);
                midSum += num;
            }
    
            // Remove oldest element
            int old = q.front(); q.pop();
            if (low.find(old) != low.end()) {
                low.erase(low.find(old));
                int moved = *mid.begin();
                mid.erase(mid.begin());
                midSum -= moved;
                low.insert(moved);
            } else if (high.find(old) != high.end()) {
                high.erase(high.find(old));
                auto it = prev(mid.end());
                int moved = *it;
                mid.erase(it);
                midSum -= moved;
                high.insert(moved);
            } else {
                mid.erase(mid.find(old));
                midSum -= old;
            }
        }
    
        int calculateMKAverage() {
            if ((int)q.size() < m) return -1;
            return midSum / (m - 2 * k);
        }
    };