#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};
void SortedStack :: sort()
{
   stack<int>st;
   while(s.size()!=0)
   {
       int x=s.top();
       s.pop();
       while(st.size()!=0 && st.top()>x)
       {
           s.push(st.top());
           st.pop();
       }
       st.push(x);
   }
   s=st;
   
}