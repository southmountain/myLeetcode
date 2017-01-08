 struct Node
{
    int freq;
    int val;
    list<int>::iterator iter;
    
    Node() : val(-1), freq(1) {}
    Node(int value) : val(value), freq(1) {}
};

class LFUCache {
    int cap;
    int size;
    int minFreq;
    unordered_map<int, Node> m; //key to {value,freq};
    unordered_map<int, list<int>>  fm;  //freq to key list;
public:
    LFUCache(int capacity) {
        cap=capacity;
        size=0;
    }
    
    int get(int key) {
        if(m.count(key)==0) return -1;
        
        fm[m[key].freq].erase(m[key].iter);
        m[key].freq++;
        fm[m[key].freq].push_front(key);
        m[key].iter = fm[m[key].freq].begin();
        
        if(fm[minFreq].size()==0 )
          minFreq=m[key].freq;
        return m[key].val;
    }
    
   void put(int key, int value) {
        if(cap<=0) return;
        
        int storedValue=get(key);
        if(storedValue!=-1)
        {
            m[key].val=value;
            return;
        }
        
        if(size>=cap )
        {
            m.erase( fm[minFreq].back() );
            fm[minFreq].pop_back();
            size--;
        }
         m[key] = {Node(value)};
        fm[1].push_front(key);
        m[key].iter=fm[1].begin();
        minFreq=1;
        size++;
    }
};