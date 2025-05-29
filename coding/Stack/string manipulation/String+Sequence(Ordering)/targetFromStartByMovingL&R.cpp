// https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/

// // O(n)
// // O(n)

bool canChange(string start, string target) {
    int n = start.size();
    int lFreqStart = 0;
    int lFreqTarget = 0;
    int rFreqStart = 0;
    int rFreqTarget = 0;

    // max nlogn time complexity 

    stack<pair<char, int>>stackStart;
    stack<pair<char, int>>stackTarget;

    for(int i = 0; i<n; i++){
        if(start[i] == 'L'){
            lFreqStart++;
            stackStart.push({start[i], i});
        }
         if(start[i] == 'R'){
            rFreqStart++;
            stackStart.push({start[i], i});
        }
         if(target[i] == 'L'){
            lFreqTarget++;
            stackTarget.push({target[i], i});
        }
         if(target[i] == 'R'){
            rFreqTarget++;
            stackTarget.push({target[i], i});
        }
    }


    if((lFreqStart != lFreqTarget) || (rFreqStart != rFreqTarget)){
        return false;
    }

    while(!stackTarget.empty() && (stackStart.top().first == stackTarget.top().first)){
        char topChar = stackStart.top().first;
        int topCharStartIdx = stackStart.top().second;
        int topCharTargetIdx = stackTarget.top().second;

        if(((topChar == 'L') && (topCharStartIdx < topCharTargetIdx)) || ((topChar == 'R') && (topCharStartIdx > topCharTargetIdx))){
            return false;
        }
        stackTarget.pop();
        stackStart.pop();
    }

    if(stackTarget.size() > 0 || stackStart.size() > 0){
        return false;
    }

    return true;
}