// link https://leetcode.com/problems/the-skyline-problem/

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    // BRUTE FORCE 
    // we will try to compute the maxm height at each key point 
    // Time : O(n^2)
    // Space : O(n)

    int numOfBuildings = buildings.size();

    // key points 
    // it will have all the key points in sorted order and no duplicates 
    set<int>keyPoints;

    for(int i = 0; i< numOfBuildings; i++){
        keyPoints.insert(buildings[i][0]);
        keyPoints.insert(buildings[i][1]);
    }

    int n = keyPoints.size();
    vector<int>edges;
    vector<int>heights(n+1, 0);

    for(auto it = keyPoints.begin(); it!= keyPoints.end(); it++){
        edges.push_back(*it);
    }

    unordered_map<int,int>edgesMap;

    for(int i = 0; i<n;i++){
        edgesMap[edges[i]] = i;
    }

    for(auto building : buildings){
        int left = building[0];
        int right = building[1];
        int currHeight = building[2];

        int leftIdx = edgesMap[left];
        int rightIdx = edgesMap[right];

        for(int i = leftIdx; i< rightIdx; i++){
            heights[i] = max(heights[i], currHeight);
        }
    }

    vector<vector<int>>answer;

    for(int i = 0; i< n;i++){
        if(i == 0 || heights[i] != heights[i-1]){
            answer.push_back({edges[i], heights[i]});
        }
    }

    return answer;

}