// https://leetcode.com/problems/number-of-flowers-in-full-bloom/description/

vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    // 0 indexed array 
    // 2d array 
    // full bloom : start to end inclusive 

    // 0 indexed : people 
    // n 
    // i : time when ith poeple came to see 

    // number of flowers blooming = number of flowers that have started blooming till that time - number of flowers that have eneded blooming 

    int bloomingInterval = flowers.size();
    int numOfPeoples = people.size();
    vector<int>origPeople(numOfPeoples, 0);

    for(int i = 0; i< numOfPeoples; i++){
     origPeople[i] = people[i];
    }

     sort(flowers.begin(), flowers.end());
    sort(people.begin(), people.end());

     // to store the num of bloomed flowers for all the people
    unordered_map<int,int>bloomedFlowers;

    // min heap to stopre the end time of blooming of flowers 
    priority_queue<int, vector<int>, greater<int>>pq;

    int j = 0;

    for(int i = 0; i< numOfPeoples; i++){
     // push all the flowers end time whish has started blooming before the person arrived
     while(j < bloomingInterval && flowers[j][0] <= people[i]){
         pq.push(flowers[j][1]);
         j++;
     }
     // reemove all the flowers which have stopped blooing before the person arrives 
     while(pq.size() > 0 && pq.top() < people[i]){
         pq.pop();
     }

     // remaining flowers that have not stopped blooming
     bloomedFlowers[people[i]] = pq.size();
    }

    vector<int>ans(numOfPeoples,0);

     for(int i = 0; i<numOfPeoples; i++){
         ans[i] = bloomedFlowers[origPeople[i]];
     }

     return ans;
 }