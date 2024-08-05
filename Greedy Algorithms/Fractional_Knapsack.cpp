#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(NlogN)+O(N)
// Spave Complexity: O(1)

struct Item{
    int value;
    int weight;
};

class Solution {
  public:
    static bool mycmp(Item a,Item b)
    {
        double r1=(a.value*1.0)/a.weight;
        double r2=(b.value*1.0)/b.weight;
        return r1>r2;
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        double totalProfit=0.0;
        sort(arr,arr+n,mycmp);
        for(int i=0;i<n;i++)
        {
            if(w>=arr[i].weight)
            {
                totalProfit+=arr[i].value;
                w=w-arr[i].weight;
            }
            else
            {
                totalProfit+=((arr[i].value*1.0)/arr[i].weight)*w;
                break;
            }
        }
        return totalProfit;
      
    }
};