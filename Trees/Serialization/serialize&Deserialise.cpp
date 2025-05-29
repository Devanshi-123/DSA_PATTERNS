

// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "NULL";
        }

        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* helper(queue<string> &q){
        if(q.empty()){
            return NULL;
        }
       string s = q.front();
       q.pop();

       if(s == "NULL"){
        return NULL;
       }

       TreeNode* root = new TreeNode(stoi(s));
       root->left = helper(q);
       root->right = helper(q);
        return root;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string>q;
        stringstream ss(data);
        string str;

        while(getline(ss, str, ',')){
            cout << "str" << str << endl;
            q.push(str);
        }

        return helper(q);
    }