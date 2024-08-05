#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
// Time Complexity: O(V+E)
// Space Complexity: O(V)
class Solution {
public:
    unordered_map<int,Node*>m;
    Node* cloneGraph(Node* node)
    {
        if(node==NULL)
            return node;
       queue<Node*>q;
       q.push(node);
       while(q.size()!=0)
       {
            Node* curr=q.front();
            q.pop();
            int currVal=curr->val;
            Node* newCurr;
            if(m.find(currVal)==m.end())
            {
                newCurr=new Node(currVal);
                m[currVal]=newCurr;
            }
            else
                newCurr=m[currVal];
            vector<Node*>res;
            for(auto it:curr->neighbors)
            {
                Node* newNeighbor;
                if(m.find(it->val)==m.end())
                {
                    newNeighbor=new Node(it->val);
                    m[it->val]=newNeighbor;
                    q.push(it);
                }
                else
                    newNeighbor=m[it->val];
                res.push_back(newNeighbor);
            }
            newCurr->neighbors=res;
       }
        return m[node->val];

        
    }
};