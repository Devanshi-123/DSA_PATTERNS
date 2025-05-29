// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/

// O(nlogn) time
// O(n) space

double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    // n workers 
    // quality 
    // wage : min wage expectation 

    // exactly k workers 
    // every worker wage >= min wage 

    // i want min wage to quality ratio as lower w:q lower is the cost 

    int n = quality.size();

    vector<pair<double,double>>rate(n);

    for(int i = 0; i<n;i++){
        double ratio = (double)wage[i]/(double)quality[i];
        rate[i] = {ratio, quality[i]};
    }

    sort(rate.begin(), rate.end());

    double totalQuality = 0;
    double totalCost = 1e18;
    priority_queue<pair<double,double>>mxHp;

    int i = 0;

    while(i<n){
        mxHp.push({rate[i].second, rate[i].first});
        totalQuality += rate[i].second;

        if(mxHp.size() == k){
            double maxRate = rate[i].first;
            totalCost = min(totalCost, totalQuality*maxRate);
            cout << "total cost" << totalCost << endl;
        }

        while(mxHp.size() > k){
            totalQuality -= mxHp.top().first;
            mxHp.pop();

            if(mxHp.size() == k){
            double maxRate = rate[i].first;
            cout << "totalQuality" << totalQuality << endl;
            cout << "max rate" << maxRate << endl;
            totalCost = min(totalCost, totalQuality*maxRate);
            cout << "total cost" << totalCost << endl;
        }
        }

        i++;
    }

    return totalCost;
    
}