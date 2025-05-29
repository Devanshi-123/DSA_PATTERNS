// https://leetcode.com/problems/remove-k-digits/description/
// we think of monotonic stack in mostly strung manipulation questions or subsequences i.e. wherever ordering matters 

string removeKdigits(string num, int k) {
    // positive num 
    int n = num.size();

    stack<int>st;

    if(n == k){
        return "0";
    }

    for(char ch : num){
        int i = ch - '0';
        while(!st.empty() && i < st.top() && k > 0){
            st.pop();
            k--;
        }
        st.push(i);
    }

    string str = "";
    while(!st.empty()){
        str += st.top() + '0';
        st.pop();
    }

    if(k > 0){
        str.erase(str.begin(), str.begin()+k);
        k = 0;
    }

    reverse(str.begin(), str.end());

    if(str == "0"){
        return str;
    }

    int j = 0;
    while(j < str.size()){
        if(str[j] != '0'){
            break;
        }
        j++;
    }

    if(j > 0){
        str.erase(str.begin(), str.begin()+j);
    }

    if(str == ""){
        return "0";
    }
    
    return str;

}