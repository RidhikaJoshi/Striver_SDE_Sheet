#include<bits/stdc++.h>
using namespace std;
// using two stacks
// time for push: o(1)
// time for pop: o(n)
// time for top: o(n)
// time for empty: o(1)
class MyQueue {
public:
    stack<int>st1,st2;
    MyQueue() {
          stack<int>st1,st2;
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(st1.size()!=1)
        {
            int x=st1.top();
            st1.pop();
            st2.push(x);
        }
        int topElelment=st1.top();
        st1.pop();
        while(st2.size()!=0)
        {
            st1.push(st2.top());
            st2.pop();
        }
        return topElelment;
        
    }
    
    int peek() {
         while(st1.size()!=1)
        {
            int x=st1.top();
            st1.pop();
            st2.push(x);
        }
        int topElelment=st1.top();
        while(st2.size()!=0)
        {
            st1.push(st2.top());
            st2.pop();
        }
        return topElelment;
        
    }
    
    bool empty() {
        if(st1.size()==0)
            return true;
        return false;
    }
};
// optimised approach
// using 2 stacks
// improved pop and peek operation
// using st1 for pushing
// using st2 for pop and peek
class MyQueue {
public:
    stack<int>st1,st2;
    MyQueue() {
        stack<int>st1,st2;
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop()
    {
        if(st2.size()!=0)
        {
            int topElement=st2.top();
            st2.pop();
            return topElement;
        }
        int topElement=-1;
        while(st1.size()!=0)
        {
            st2.push(st1.top());
            st1.pop();
        }
        topElement=st2.top();
        st2.pop();
        return topElement;
    }
    
    int peek() {
        if(st2.size()!=0)
        {
            int topElement=st2.top();
            return topElement;
        }
        int topElement=-1;
        while(st1.size()!=0)
        {
            st2.push(st1.top());
            st1.pop();
        }
        topElement=st2.top();
        return topElement;
        
    }
    
    bool empty() {
        if(st1.size()==0 && st2.size()==0)
            return true;
        return false;
        
    }
};