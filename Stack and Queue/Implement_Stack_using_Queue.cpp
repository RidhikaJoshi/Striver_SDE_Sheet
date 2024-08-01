#include<bits/stdc++.h>
using namespace std;
// using single queue
// time for push: o(1)
// time for pop: o(n)
// time for top: o(n)
// time for empty: o(1)
class MyStack {
public:
    queue<int>q;
    MyStack() {
        queue<int>q;
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int count=q.size();
        while(count!=1)
        {
            int x=q.front();
            q.pop();
            count--;
            q.push(x);
        }
        int x=q.front();
        q.pop();
        return x;
        
    }
    
    int top() {
        int count=q.size();
        while(count!=1)
        {
            int x=q.front();
            q.pop();
            count--;
            q.push(x);
        }
        int x=q.front();
        q.pop();
        q.push(x);
        return x;
    }
    
    bool empty() {
        if(q.size()==0)
            return true;
        return false;
    }
};