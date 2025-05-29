// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/


// O(n) time and O(1) space

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// since this is a perfect binary tree no need to check for null
// and also no need to check for left and right child
// as every parent will have 2 children
class Solution {
    public:
        Node* connect(Node* root) {
            // perfect : every parent -> 2 children 
            if(root == NULL){
                return NULL;
            }
    
            queue<Node*>q;
            q.push(root);
    
            while(!q.empty()){
                int n = q.size();
                Node* prev = q.front();
                q.pop();
                if(prev->left){
                    q.push(prev->left);
                }
                if(prev->right){
                    q.push(prev->right);
                }
                for(int i = 1; i<n;i++){
                    Node* node = q.front();
                    q.pop();
                    prev->next = node;
                    prev = node;
                     if(node->left){
                    q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                }
            }
    
            return root;
        }
    };

// Variation 

// If it is just a binary tree then we can use the following approach
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
    // perfect : every parent -> 2 children 
        if(root == NULL){
            return NULL;
        }

        queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            Node* prev = q.front();
            q.pop();
            if(prev->left){
                q.push(prev->left);
            }
            if(prev->right){
                q.push(prev->right);
            }
            for(int i = 1; i<n;i++){
                Node* node = q.front();
                q.pop();
                prev->next = node;
                prev = node;
                    if(node->left){
                q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};