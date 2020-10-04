class LRUCache {
        list<pair<int,int>> cache;
        unordered_map<int,list<pair<int,int>>::iterator> mymap;  //Key, address in dequeue PAIR
        
        void refreshPosition(int key,int value)
        {
            cache.erase(mymap[key]);
            cache.push_front(make_pair(key,value));
            mymap[key] = cache.begin();     //Addr of new position stored in map
        }
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mymap.find(key)!=mymap.end())
        {
            refreshPosition(key,(*mymap[key]).second);
            return (*mymap[key]).second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mymap.find(key)!=mymap.end())
            refreshPosition(key,value);
        else
        {
            //Add to cache
            cache.push_front(make_pair(key,value));
            mymap[key] = cache.begin();
            if(mymap.size()>capacity)
            {
                mymap.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};