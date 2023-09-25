/*Given two integer array A and B of size N each.
A sum combination is made by adding one element from array A and another element of array B.
Return the maximum K valid sum combinations from all the possible sum combinations.

Note : Output array must be sorted in non-increasing order.*/

#include <bits/stdc++.h>
using namespace std;
// Time-O(NlogN)+O(K)
// Space -O(K)*2;
class Solution
{
public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B)
    {
        sort(A.rbegin(), A.rend());
        sort(B.rbegin(), B.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j < K; j++)
            {
                pq.push(A[i] + B[j]);
                if (pq.size() > K)
                    pq.pop();
            }
        }
        int j = 1;
        vector<int> res(K);
        while (pq.size() != 0)
        {
            res[K - j] = pq.top();
            pq.pop();
            j++;
        }
        return res;
    }
};