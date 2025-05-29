// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/

// Time : O(nklogn)
// Space : O(n)

int findXsum(unordered_map<int,int> &freq, int x){
    // max heap 
    vector<pair<int,int>>freqVec;
    for(auto it = freq.begin(); it != freq.end(); it++){
        freqVec.push_back({it->second, it->first});
    }

    sort(freqVec.begin(), freqVec.end(), [](pair<int,int>a, pair<int,int>b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first > b.first;
    });

    int xsum = 0;

    for(int i = 0; i<x;i++){
        xsum += freqVec[i].first*freqVec[i].second;
    }

    return xsum;

}
vector<int> findXSum(vector<int>& nums, int k, int x) {
    // x sum : 

    int i = 0;
    int j = 0;
    int n = nums.size();
    vector<int>vec;

    unordered_map<int,int>freq;

    while(j < n){
        freq[nums[j]]++;

        // invalid 
        while(j-i+1 > k && i<=j){
            if(freq[nums[i]] > 1){
                freq[nums[i]]--;
            }else {
                freq.erase(nums[i]);
            }
            i++;
        }

        if(j-i+1 == k){
            int xsum = 0;
            if(freq.size() <= x){
                for(auto it = freq.begin(); it != freq.end(); it++){
                    xsum += it->first*it->second;
                }
            }else {
                xsum = findXsum(freq, x);
            }
            vec.push_back(xsum);
        }

        j++;
    }
    return vec;
}