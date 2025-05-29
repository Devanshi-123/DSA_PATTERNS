// https://leetcode.com/problems/k-th-smallest-prime-fraction/submissions/1603800093/

// // Time Complexity: O(n^2)
// // Space Complexity: O(n)

// Identify : k will be given 

vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    // sorted 
    // unique 
    // 1 and prime numbers 

    // k : think of heap 

    // kth smallest fraction : maxHeap 

    priority_queue<pair<float, pair<int,int>>>pq;

    int n = arr.size();

    for(int i = 0; i<n ; i++){
        for(int j = i+1; j<n; j++){
            float div = (float)arr[i]/(float)arr[j];
            pq.push({div, {arr[i], arr[j]}});
        }
    }

    while(pq.size() > k){
        pq.pop();
    }

    vector<int>answer;

    answer.push_back(pq.top().second.first);
    answer.push_back(pq.top().second.second);

    return answer;

}