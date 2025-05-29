// dFS 

Node* dfs(Node* node, unordered_map<Node*, Node*> &cloneMap){
    // cout << "val" << temp->val << endl;
   // if(it already exit return )
   if(cloneMap.find(node) != cloneMap.end()){
    return cloneMap[node];
   }

   Node* clonedNode = new Node(node->val);
   cloneMap[node] = clonedNode;

    // explore neigh 
    for(auto neigh : node->neighbors){
           cloneMap[node]->neighbors.push_back(dfs(neigh, cloneMap));
    }

    return clonedNode;
}
Node* cloneGraph(Node* node) {
    // connected , undireected graph 

    // node -> val ->idx (1 based indexing)
    if(node == NULL){
        return NULL;
    }

    unordered_map<Node*, Node*>cloneMap;

    return dfs(node, cloneMap);
}


// bfs 

Node* cloneGraph(Node* node) {
    // connected 
    // undirected graph 

    // node -> val , list [neighs]

    // bfs 

    if(node == NULL){
        return NULL;
    }

    queue<Node*>q;
    q.push(node);

    unordered_map<Node*, Node*>cloneMap;

    Node* clonedNode = new Node(node->val);
    cloneMap[node] = clonedNode;

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        for(auto neigh : curr->neighbors){
            // if the neighbour is not already cloned then clone it 
            if(cloneMap.find(neigh) == cloneMap.end()){
                Node* clonedNeighbour = new Node(neigh->val);
                cloneMap[neigh] = clonedNeighbour;
                q.push(neigh);
            }

            cloneMap[curr]->neighbors.push_back(cloneMap[neigh]);
        }
        
    }

    return clonedNode;
}