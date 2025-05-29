// https://leetcode.com/problems/moving-average-from-data-stream/description/

// Time : O(n)
// Space : O(n)

class MovingAverage {
    public:
        vector<int>vec;
        int n = 0;
        int k = 0;
        int count = 0;
        MovingAverage(int size) {
            for(int i = 0; i<size; i++){
                vec.push_back(0);
            }
            n = size;
        }
        
        double next(int val) {
            vec[k] = val;
            k = (k+1)%n;
            if(count < n){
                count++;
            }
            double sum = 0;
            for(int i=0; i<n;i++){
                sum += vec[i];
            }
            return sum/count;
        }
    };