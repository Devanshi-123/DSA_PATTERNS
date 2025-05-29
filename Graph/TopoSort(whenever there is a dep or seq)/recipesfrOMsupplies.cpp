// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/submissions/1600117546/

vector<string>  bfs(queue<string> &q,unordered_map<string, bool> &vis,unordered_map<string, int> &inDegree,unordered_map<string, int> &suppliesMap,unordered_map<string, vector<string>> &dependenciesMap,vector<string> &recipes,unordered_map<string, vector<string>>&ingredientsMap){
    vector<string>ans;
    while(!q.empty()){
        string currRecipe = q.front();

        cout << "recipe" << currRecipe << endl;

        q.pop();
        bool flag = true;

        for(auto ing: ingredientsMap[currRecipe]){
            cout << "ing" << ing << endl;
            if(suppliesMap.find(ing) == suppliesMap.end()){
                flag = false;
                break;
            }
        }

        if(flag == true){
            suppliesMap[currRecipe] = 1;
            ans.push_back(currRecipe);
        }

        if(dependenciesMap.find(currRecipe) != dependenciesMap.end() && flag == true){
            for(auto dep : dependenciesMap[currRecipe]){
                inDegree[dep]--;
                if(inDegree[dep] == 0 && vis.find(dep) == vis.end()){
                    vis[dep] = true;
                    q.push(dep);
                }
            }
        }

    }
    return ans;
}
vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    unordered_map<string, int>inDegree;
    unordered_map<string, int>suppliesMap;
    unordered_map<string, vector<string>>dependenciesMap;
    unordered_map<string, vector<string>>ingredientsMap;


    int numOfRecipes = recipes.size();
    int numOfSupplies = supplies.size();

    for(int i = 0; i<numOfSupplies; i++){
        suppliesMap[supplies[i]]++;
    }

    // for all the recipes go throough its ingredients 
    for(int i = 0; i<numOfRecipes; i++){
        for(auto ing : ingredients[i]){
            // if the ingredient is not in the supplies list 
            // increase the indegree of current recipe
            if(suppliesMap.find(ing) == suppliesMap.end()){
                inDegree[recipes[i]]++;
                dependenciesMap[ing].push_back(recipes[i]);
            }
            ingredientsMap[recipes[i]].push_back(ing);
        }
        if(inDegree.find(recipes[i]) == inDegree.end()){
            inDegree[recipes[i]] = 0;
        }
    }

 

    queue<string>q;
    unordered_map<string, bool>vis;

    for(auto it = inDegree.begin(); it!= inDegree.end(); it++){
        if(it->second == 0){
            q.push(it->first);
            vis[it->first] = true;
        }
    }

    return bfs(q, vis, inDegree, suppliesMap, dependenciesMap, recipes, ingredientsMap);
}