#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(NlogN)+O(N*m)
// Space Complexity: O(N)
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution 
{
    public:
    static bool mycmp(Job a,Job b)
    {
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
       sort(arr,arr+n,mycmp);
       vector<int>work(n,-1);
       int countWork=0,totalProfit=0;
       for(int i=0;i<n;i++)
       {
            
           int deadId=arr[i].dead;
           for(int k=deadId-1;k>=0;k--)
           {
               if(work[k]==-1)
               {
                    work[k]=arr[i].id;
                    //cout << k << " " << arr[i].profit << endl;
                    totalProfit+=arr[i].profit;
                    countWork++;
                    break;
               }
           }
       }
       return {countWork,totalProfit};
       
    } 
};