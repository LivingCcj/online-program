#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

struct Value{
    int value;
    list<int>::iterator iter;
    Value(int v,list<int>::iterator it):value(v),iter(it){}
};

class LRUCache
{
private:
    unordered_map<int, Value> m_hash;
    list<int> cache;
    int cap=0;
public:
    LRUCache(int n);
    void put(int key,int value);
    int get(int key);
};

LRUCache::LRUCache(int n)
{
    cap=n;
    m_hash.reserve(cap*2);
}

int LRUCache::get(int key){
    unordered_map<int,Value>::iterator iter =  m_hash.find(key);
    if(iter!=m_hash.end()){
        cache.splice(cache.begin(),cache,iter->second.iter);
        return iter->second.value;
    }else{
        // cout<<"-1"<<endl;
        return -1;
    }
}



void LRUCache::put(int key,int value){
    unordered_map<int,Value>::iterator iter=m_hash.find(key);
    if(iter!=m_hash.end()){
        iter->second.value=value;
        cache.splice(cache.begin(),cache,iter->second.iter);
        
    }else{
        if(cache.size()==cap){
            m_hash.erase(cache.back());
            cache.pop_back();
        }
        cache.push_front(key);
        Value v(value,cache.begin());
        m_hash.insert(pair<int,Value>(key,v));
        cache.erase();
    }
}


int main(){
    LRUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    cout<<cache.get(2)<<endl;

    cache.put(3,3);
    cout<<cache.get(1)<<endl;
    cout<<cache.get(2)<<endl;
    cout<<cache.get(3)<<endl;
}