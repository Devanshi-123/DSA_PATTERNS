// https://leetcode.com/problems/remove-element/

int removeElement(vector<int>& nums, int val) {
    // n log n 

    sort(nums.begin(), nums.end());

    auto ub = upper_bound(nums.begin(), nums.end(), val);
    auto lb = lower_bound(nums.begin(), nums.end(), val);

    int freq = ub-lb;

    cout << "freq" << freq << endl;

    nums.erase(lb, ub);

    return nums.size();
}