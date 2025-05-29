// https://leetcode.com/problems/two-sum-iii-data-structure-design/submissions/1603588534/

vector<int>vec;
TwoSum() {
    
}

void add(int number) {
    vec.push_back(number);
}

bool find(int value) {
    // two pointer 

    sort(vec.begin(), vec.end());
    int n = vec.size();
    int left = 0;
    int right = n-1;

    while(left < right){
        int sum = vec[left] + vec[right];

        if(sum == value){
            return true;
        }else if(sum < value){
            left++;
        }else {
            right--;
        }
    }
    return false;
}

// Time : O(nlogn) for sorting
// Space : O(n) for storing the numbers