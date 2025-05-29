// https://leetcode.com/problems/find-the-most-competitive-subsequence/description/

// Time : O(n)
// Space : O(n)
// Approach : Monotonic Stack
// 1. We need to find the most competitive subsequence of size k from the given array nums.
// 2. The most competitive subsequence is the one that has the smallest lexicographical order.
// 3. We can use a monotonic stack to maintain the smallest elements in the subsequence.
// 4. We iterate through the array and for each element, we check if it is smaller than the top of the stack.
// 5. If it is smaller, we pop the top element from the stack until we find a smaller element or the stack is empty.
// 6. We also need to check if we can still form a subsequence of size k after popping elements from the stack.
// 7. If the stack size is less than k, we push the current element into the stack.
// 8. Finally, we reverse the stack to get the correct order of the subsequence.
// 9. We return the stack as the result.
// 10. The time complexity of this approach is O(n) and the space complexity is O(n).
// 11. The space complexity is O(n) because we are using a stack to store the elements of the subsequence.

vector<int> mostCompetitive(vector<int>& nums, int k) {
    // monotonic stack 

    int n = nums.size();
    stack<int>st;

    for(int i = 0; i<n;i++){
        // even after removing 1 elemenet we should have enough elements to make a k size subseq 
        // if we have a smaller element at the right then pop
        while(!st.empty() && nums[i] < st.top() && (st.size()-1+n-i >= k)){
            st.pop();
        }

        if(st.size() < k){
            st.push(nums[i]);
        }
    }

    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}