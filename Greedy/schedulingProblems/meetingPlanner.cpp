// https://www.tryexponent.com/practice/prepare/time-planner

// Brute : O(n*m)

#include <iostream>
#include <vector>

using namespace std;

vector<int> meetingPlanner( const vector<vector<int>>& slotsA, const vector<vector<int>>& slotsB, int dur) 
{
  // your code goes here

  int n = slotsA.size();
  int m = slotsB.size();

  vector<int>ans;

  for(int i = 0; i<n;i++){
    for(int j = 0; j<m;j++){
      int mx = max(slotsA[i][0], slotsB[j][0]);
      int mn = min(slotsA[i][1], slotsB[j][1]);
      if(mx + dur <= mn){
        ans.push_back(mx);
        ans.push_back(mx+dur);
        return ans;
      }
    }
  }
  return ans;
}

int main() {
  return 0;
}

// Two pointer 
// O(n+m)

vector<int> meetingPlanner( const vector<vector<int>>& slotsA, const vector<vector<int>>& slotsB, int dur) 
{
  // your code goes here

  int i = 0;
  int j = 0;

  int n = slotsA.size();
  int m = slotsB.size();

  vector<int>ans;

  while(i <n && j < m){
    int mx = max(slotsA[i][0], slotsB[j][0]);
    int mn = min(slotsA[i][1], slotsB[j][1]);

    if(mx + dur <= mn){
      ans.push_back(mx);
      ans.push_back(mx+dur);
      return ans;
    }

    // we move from smaller 
    if(slotsA[i][1] <= slotsB[j][1]){
      i++;
    }else {
      j++;
    }
  }
  return ans;
}

int main() {
  return 0;
}