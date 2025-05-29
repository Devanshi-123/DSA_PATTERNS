// https://leetcode.com/problems/separate-black-and-white-balls/description/

// time : O(nlogn)
// space : O(1)

long long minimumSteps(string s) {
    int n = s.size();

    long long count = 0;

    if(n == 1){
        return count;
    }

    set<int>unproceddedZeroes;

    for(int i = 0; i< n;i++){
        if(s[i] == '0'){
            unproceddedZeroes.insert(i);
        }
    }

    int i = 0;

    while(i < n){
        if(s[i] == '1'){
            if(unproceddedZeroes.size() > 0){
                int idx = *unproceddedZeroes.begin();
                cout << "idx" << idx << endl;
                swap(s[i], s[idx]);
                count += idx-i;
                unproceddedZeroes.erase(unproceddedZeroes.begin());
            }else {
                return count;
            }
        }else {
            unproceddedZeroes.erase(unproceddedZeroes.begin());
        }
        i++;
    }

    return count;
}