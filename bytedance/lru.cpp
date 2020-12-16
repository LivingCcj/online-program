/*
 * @Description: 最近最久未使用算法 https://www.nowcoder.com/practice/e3769a5f49894d49b871c09cadd13a61?tpId=117&&tqId=1006010
 * 
 * 使用得数据结构和方法
 vector:遍历就行
 list: pop_back(),push_front(), erase(iter->second)，back(),begin()
 map : find() erase(key) []更新值，end(), size()
 *  @Author: ccj
 * @Date: 2020-12-15 15:46:15
 * @LastEditTime: 2020-12-15 16:52:04
 * @LastEditors:  
 */

#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
using namespace std;

class lru
{
private:
    int cap;
    list<pair<int,int>> mlist;
    unordered_map<int,list<pair<int,int>>::iterator> smap;

public:
    lru(int n);
    ~lru();

    int get(int key);
    void set(int key,int value);
    vector<int> op(vector<vector<int> >& operators, int k);
};

lru::lru(int n)
{
    cap=n;
}

lru::~lru()
{
}

int lru::get(int key){
    auto iter=smap.find(key);
    if(iter==smap.end()){
        return -1;
    }   

    auto value=iter->second->second;
    mlist.push_front({key,value});
    mlist.erase(iter->second);
    smap[key]=mlist.begin();
    return value;
}

void lru::set(int key,int value){
    auto iter=smap.find(key);
    if(iter!=smap.end()){
        mlist.erase(iter->second);
    }
    //先插入后delete最后一个元素
    mlist.push_front({key,value});
    smap[key]=mlist.begin();

    if(smap.size()>cap){
        int key=mlist.back().first;
        mlist.pop_back();
        smap.erase(key);
    }
}
vector<int> lru::op(vector<vector<int> >& operators, int k) {
        // write code here
        vector<int> res;
        cap=k;
        for(auto op:operators){
            if(op[0]==1){
                set(op[1], op[2]);
            }else{
                res.push_back(get(op[1]));
            }
        }
        return res;
    }



int main(){
    lru *l = new lru(5);
   

    vector<vector<int>> data{{1,1,1},{1,2,2},{1,3,2},{2,1},{1,4,4},{2,2}};
    int k;
    cin>>k;
    vector<int> res = l->op(data,k);

    for(int i:res){
        cout<<i<<" ";
    }
    return 0;

}