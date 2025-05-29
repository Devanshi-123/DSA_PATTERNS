// https://leetcode.com/problems/find-k-closest-elements/


vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // given : 
        // sorted arr 
        // k , x

        // heap 
        // max heap : {diff, elem}
        // remove the elem till saize > k

        priority_queue<pair<int,int>>mxHp;

        int n = arr.size();

        for(int i = 0; i<n;i++){
            int diff = abs(arr[i] - x);
            mxHp.push({diff, arr[i]});
        } 

        vector<int>ans;

        while(mxHp.size() > k){
            mxHp.pop();
        }

        while(!mxHp.empty()){
            int elem = mxHp.top().second;
            ans.push_back(elem);
            mxHp.pop();
        }


        sort(ans.begin(), ans.end());

        return ans;
    }