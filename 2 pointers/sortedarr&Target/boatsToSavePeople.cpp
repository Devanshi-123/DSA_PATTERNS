// https://leetcode.com/problems/boats-to-save-people/description/

int numRescueBoats(vector<int>& people, int limit) {
    int n = people.size();

    if(n == 1){
        return 1;
    }

    sort(people.begin(),people.end());

    int i = 0;
    int j = n-1;

    int count = 0;

    while(i <= j){
        if(people[i] + people[j] <= limit){
            count++;
            i++;
            j--;
        }else {
            count++;
            j--;
        }
    }

    return count;
}