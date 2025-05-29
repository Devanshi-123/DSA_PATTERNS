// kth permutation of the sequence given k and n 

// https://leetcode.com/problems/permutation-sequence/
// time : O(n*n!) => O(n*k)
// space : O(n)

void nextPermutation(string &str, int n){
        // next permutation
        int i = n-2;

        while(i >= 0 && str[i] >= str[i+1]){
            i--;
        }

        if(i >= 0){
            int j = n-1;
            while(j > i){
                if(str[j] > str[i]){
                    swap(str[i], str[j]);
                    break;
                }
                j--;
            }
        }

        reverse(str.begin()+i+1, str.end());
        return;
    }
    string helper(string &str, int n, int k){
        int i = 1;
        while(i < k){
            nextPermutation(str, n);
            i++;
        }
        return str;
    }
    string getPermutation(int n, int k) {
        string str = "";
        for(int i = 1; i<=n;i++){
            str += to_string(i);
        }

        if(n == 1){
            return str;
        }

        if(n == 2){
            if(k == 1){
                return "12";
            }else {
                return "21";
            }
        }

        if(k == 1){
            return str;
        }

        return helper(str, n, k);
    }