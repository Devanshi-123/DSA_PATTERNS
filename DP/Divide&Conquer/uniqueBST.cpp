// https://leetcode.com/problems/unique-binary-search-trees-ii/

// time complexity is O(n*Catalan(n)) and space complexity is O(n)
// (Catalan(n) : 4^n/n^(3/2)) -> 4^n/sqrt(n)

 vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*>ans;
        if(start > end){
            ans.push_back(NULL);
            return ans;
        }
        // i will be the root node 
        for(int i = start; i<= end; i++){
            // since all the elem of left sub tree are smaller than root
            vector<TreeNode*>leftTrees = helper(start, i-1);
            // since all the elem of right sub tree are greater than root
            vector<TreeNode*>rightTrees = helper(i+1, end);

            // now combine every lefttree with every righttree 
            for(int j = 0; j<leftTrees.size(); j++){
                TreeNode* left = leftTrees[j];
                for(int k = 0; k<rightTrees.size(); k++){
                     TreeNode* right = rightTrees[k];
                     TreeNode* node = new TreeNode(i, left, right);
                    ans.push_back(node);
                }
            }
        }

        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>ans;

        if(n == 0){
            return ans;
        }

        if(n == 1){
            TreeNode* node = new TreeNode(1);
            ans.push_back(node);
            return ans;
        }

        return helper(1, n);
    }