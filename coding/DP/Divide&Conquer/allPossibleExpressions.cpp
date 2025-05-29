// https://leetcode.com/problems/different-ways-to-add-parentheses/

// time complexity is O(2^n) and space complexity is O(n)
class Solution {
public:
    vector<int> helper(string expression, int i, int j){
        vector<int>ans;
        // if this segment from i to j is a single number just return it as we cannot further split it  
        // base case 
        bool isNumber = true;
        for(int k = i; k<=j;k++){
            if(expression[k] == '+' || expression[k] == '-' || expression[k] == '*'){
                isNumber = false;
            }
        }

        if(isNumber){
            string str = expression.substr(i, j-i+1);
            int num = stoi(str);
            return {num};
        }

        // we can split it on expression 
        for(int k = i; k<=j;k++){
            if(expression[k] == '+' || expression[k] == '-' || expression[k] == '*'){
                vector<int>left = helper(expression, i, k-1);
                vector<int>right = helper(expression, k+1, j);

                for(int l : left){
                    for(int r: right){
                        if(expression[k] == '+'){
                            ans.push_back(l+r);
                        }else if(expression[k] == '-'){
                            ans.push_back(l-r);
                        }else {
                            ans.push_back(l*r);
                        }
                    }
                }
            }
        }

        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int>ans;
        int n = expression.size();

        if(n == 0){
            ans.push_back(0);
            return ans;
        }

        if(n == 1){
            ans.push_back(stoi(expression));
            return ans;
        }

        // divide and conquer 
        // whenever its like we are diciding our problem into two subproblems 
        // think of tree recursion or dicide and conquer 

        // this recursive func will evaluate the expression from i to j assuming wer have applied brackets at i and j 
        return helper(expression, 0, n-1);

    }
};