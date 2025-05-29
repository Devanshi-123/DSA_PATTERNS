// DEesign a cache we will use a map for searching a linked list to store the most freq anbd least freq used elem 

// Time : O(1)
// Space : O(capacity)


class LRUCache {
    public:
        unordered_map<int,pair<int, list<int>::iterator>>cacheStore;
        list<int>recentKeys;
        int cacheCapacity;
        LRUCache(int capacity) {
            cacheCapacity = capacity;
        }
        
        int get(int key) {
            if(cacheStore.find(key) != cacheStore.end()){
                recentKeys.erase(cacheStore[key].second);
                recentKeys.push_front(key);
                cacheStore[key].second = recentKeys.begin();
                return cacheStore[key].first;
            }
    
            return -1;
        }
        
        void put(int key, int value) {
            if(cacheStore.find(key) != cacheStore.end()){
                recentKeys.erase(cacheStore[key].second);
                cacheStore[key].first = value;
                recentKeys.push_front(key);
                cacheStore[key].second = recentKeys.begin();
    
            }else {
                if(cacheStore.size() == cacheCapacity){
                    int keyToEvict = recentKeys.back();
                    cout << "keyto evct" << keyToEvict << endl;
                    recentKeys.pop_back();
                    cacheStore.erase(keyToEvict);
                }
                cacheStore[key].first = value;
                recentKeys.push_front(key);
                cacheStore[key].second = recentKeys.begin();
            }
        }
    };
    