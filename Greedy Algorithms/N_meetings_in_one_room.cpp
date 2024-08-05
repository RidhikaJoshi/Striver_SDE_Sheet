#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(N)+O(NlogN)+O(N)
// Space Complexity: O(N)
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool mycmp(pair<int,int>a,pair<int,int>b)
    {
        return a.second<b.second;
    }
    int maxMeetings(int n, int start[], int end[])
    {
        vector<pair<int,int>>times;
        for(int i=0;i<n;i++)
        {
            times.push_back({start[i],end[i]});
        }
        sort(times.begin(),times.end(),mycmp);
        int s=times[0].first;
        int e=times[0].second;
        int countMeeting=1;
        for(int i=1;i<n;i++)
        {
            if(times[i].first>e)
            {
                countMeeting++;
                s=times[i].first;
                e=times[i].second;
            }
        }
        return countMeeting;
    }
};