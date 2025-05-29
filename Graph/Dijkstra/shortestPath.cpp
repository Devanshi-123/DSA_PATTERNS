// https://leetcode.com/problems/shortest-path-in-a-weighted-tree/description/?envType=problem-list-v2&envId=tree

void dijkstra(vector<unordered_map<int,int>> &adjList, int n,vector<int> &dist, queue<int> &q, int src){
	while(!q.empty()) {
		int src = q.front();
		q.pop();
	
	// explore neigh 
	for(auto neigh : adjList[src]) {
		int dest = neigh.first;
		int wt = adjList[src][dest];
		
		if(dist[src] != INT_MAX && (dist[src] + wt < dist[dest])) {
			dist[dest] = dist[src] + wt;
			q.push(dest);
		}
	}
}
}


void helper(vector<int> &dist, int diff, int src, vector<unordered_map<int, int>> &adjList) {
	dist[src] += diff;
	for(auto neigh : adjList[src]) {
        helper(dist, diff, neigh.first, adjList);
    }
}
 
void updateDistance(int src,int dest,int updatedWeight,vector<int> &dist, vector<unordered_map<int,int>> &adjList) {

    if(adjList[src].find(dest) == adjList[src].end()){
        swap(src, dest);
    }

	int currWeight = adjList[src][dest];
	int diff = updatedWeight - currWeight;
	adjList[src][dest] = updatedWeight;
	
	helper(dist, diff, dest, adjList);
	
}
vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
      // create a adj list from edges 
	
	int numEdges = n-1;

	vector<unordered_map<int,int>>adjList(n+1);

	for(auto edge : edges) {
		int u = edge[0];
		int v = edge[1];
		int wt = edge[2];
		
		adjList[u][v] = wt;
  	 }

	vector<int>dist(n+1, INT_MAX);
	queue<int>q;

	dist[1] = 0;
	q.push(1);

	dijkstra(adjList, n, dist, q, 1);


	vector<int>ans;

	for(auto query : queries) {
		int type = query[0];

		if(type == 2){
			int num = query[1];
			ans.push_back(dist[num]);
		}else {
			int src = query[1];
            int dest = query[2];
            int updatedWeight = query[3];	 
            updateDistance(src, dest, updatedWeight, dist, adjList);
		}

	}

	return ans;
	}