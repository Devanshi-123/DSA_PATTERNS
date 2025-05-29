// https://leetcode.com/problems/minimum-window-substring/

class Solution {
    private:
        bool containsT(unordered_map<char, int> &sMap, unordered_map<char, int> &tMap){
            for(auto it = tMap.begin(); it != tMap.end(); it++){
                if(sMap.find(it->first) == sMap.end() || sMap[it->first] < it->second){
                    return false;
                }
            }
            return true;
        }
    public:
        string minWindow(string s, string t) {
            int m = s.size();
            int n = t.size();
    
            unordered_map<char, int>tMap;
            unordered_map<char, int>sMap;
    
            for(char ch : t){
                tMap[ch]++;
            }
    
            int i = 0;
            int j = 0;
    
            int minLen = INT_MAX;
            string minStr = "";
            string str = "";
    
            while(j < m){
                sMap[s[j]]++;
                str += s[j];
    
                while(((tMap.find(s[i]) == tMap.end()) || (tMap.find(s[i]) != tMap.end() && sMap[s[i]] > tMap[s[i]])) && i <= j && str.size() > t.size()){           
                    if(sMap[s[i]] > 1){
                    sMap[s[i]]--;
                    }else {
                        sMap.erase(s[i]);
                    }
                    str.erase(str.begin());
                    i++;
                    cout << "i" << i << endl;
                }
    
                if(containsT(sMap, tMap)){
                    if(str.size() <= minLen){
                    minStr = str;
                    minLen = str.size();
                }
                }
               
    
                j++;
            }
    
            return minStr;
        }
    };