// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/submissions/1642837431/

// Time : O(nlog(maxQty))
// Space : O(1)

bool isValid(int maxQty, vector<int> &quantities, int m, int numStores){
        int storesAssigned = 0;
        for(int i = 0; i<m;i++){
            storesAssigned += ceil((float)quantities[i]/(float)maxQty);
        }

        return storesAssigned <= numStores;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        // n stores 
        // m type of products : quantities : quantity of ith type of product 

        // allocate / distribute product to stores 

        // rules : 
        // 1 stoe : 1 type of product but any amoutn of it 
        // minimize the maxm quantity of product at any store 

        // n : 6 
        // [11, 6]

        int typeOfProducts = quantities.size();

        int start = 1;
        int end = *max_element(quantities.begin(), quantities.end());

        int ans = -1;

        while(start <= end){
            int mid = start + (end-start)/2;

            

            if(isValid(mid, quantities, typeOfProducts, n)){
                ans = mid;
                end = mid-1;
            }else {
                start = mid+1;
            }
        }
        return ans;
    }