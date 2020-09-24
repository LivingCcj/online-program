#include<iostream>
#include<map>
using namespace std;

//使用双向链表实现lru算法。


template<class Key,class Value>
class Node(){
    
public:
    Key key;
    Value vaule;

    Node* prer;
    Node* next;
    Node(Key k,Vaule v):key(k),vaule(v){};

};

class LRU{

public:
    void removeLast(){
       if(last!=nullptr){
           last=last.pre;
           if(last==nullptr){
               first=nullptr;
           }else{
               last.next=nullptr;
           }
       }
    }

    Node get(Node &n){
        Node tmp=data[n.key];
        if(tmp!=nullptr){
            return nullptr;
        }
        // removeToHead(tmp);s
        return tmp;
        
    }



    void put(int i,char ch){
        Node<int,char> node=data[i];
        if(node==nullptr){
            if(data.size()>capcity){
                data.erase(last.key);
                removeLast();
            }
            Node<int,char> n(i,ch);
            data[i]=n;
            currenctSize++;
        }else{
            node.value=ch;
        }
        moveToHead(node);
    }
    //移动到头
    void moveToHead(Node &node){
        if(first==node){
            return ;
        }

        if(node.next!=nullptr){
            node.pre.next=node.next;
        }
        if(node.pre!=nullptr){
            node.next.pre=node.pre;
        }
        if(node == last){
            node.pre.next=nullptr;
        }
        if(last == null && first==null){
            last=node;
            first=node;
            return ;
        }
        node.next=first;
        first.prt=node;
        first=node;
        node.pre=nullptr;
    }

    void removeNode(int key){
        Node<int,char> node=data[key];
        if(node!=nullptr){
            if(node.pre!=nullptr){
                node.next.pre=node.pre;
            }
            if(node.next!=nullptr){
                node.pre.next=node.next;
            }

            if(first==node){
                first=first.next;
            }
            if(last==node){
                last=last.pre; 
            }
        }
        data.erase(key);
    }
    void clearAll(){
        first=nullptr;
        last=nullptr;
        data.clear();
    }

    void LRU(int size){
        capcity=size;
        currenctSize=0;
        map<int,Node<int,char>> temp(size);
        data=&temp;
    }
private:
    Node<int,char> first;
    Node<int,char> end;
    map<int,Node<int,char>>* data;
    int capcity;
    int currenctSize;
};


class LRUCache
{
private:
    
public:
    LRUCache(int cap);
    int get(int key);
    void put(int key,int vaule);
};

LRUCache::LRUCache(int cap)
{
}
