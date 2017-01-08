class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(cachemap.find(key)==cachemap.end())return -1;
        LRUcache.splice(LRUcache.begin(),LRUcache,cachemap[key]);
        cachemap[key]=LRUcache.begin();
        return LRUcache.begin()->value;
    }
    
    void set(int key, int value) {
        if(cachemap.find(key)==cachemap.end())
        {
            if(LRUcache.size()==capacity)
            {
                cachemap.erase(LRUcache.back().key);
                LRUcache.pop_back();
            }
            LRUcache.push_front(cache(key,value));
            cachemap[key]=LRUcache.begin();
        }else
        {
            cachemap[key]->value=value;
            LRUcache.splice(LRUcache.begin(),LRUcache,cachemap[key]);
            cachemap[key]=LRUcache.begin();
        }
    }
private:
    struct cache{
        int key;
        int value;
        cache(int k,int v):key(k),value(v){}
    };
    int capacity;
    list<cache>LRUcache;
    unordered_map<int,list<cache>::iterator>cachemap;
    
};