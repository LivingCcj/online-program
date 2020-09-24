#include<stack>
#include<iostream>
using namespace std;
class SortedStack {
public:
    SortedStack() {
        
    }
    
    void push(int val) {
        while(!s1.empty() && s1.top()>val){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    void pop() {
        if(!s1.empty()){
            s1.pop();
        }
    }
    
    int peek() { 
        if(s1.empty()){
            return -1;
        }else{
            return s1.top();
        }

    }
    
    bool isEmpty() {
        return s1.empty();
    }
private:
    stack<int> s1;
    stack<int> s2; //辅助栈
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */

int main(){
    SortedStack* obj= new SortedStack();
    obj->push(1);
    obj->push(4);
    obj->push(3);
    obj->push(8);
    obj->push(9);
    
    while(!obj->isEmpty()){
        int tmp=obj->peek();
        cout<<tmp<<endl;
        obj->pop();
    }
    cout<<abs(-1)<<endl;
    return 0;
}