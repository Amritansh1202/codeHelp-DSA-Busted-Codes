#include <iostream>
#include <heap>
#include <queue>
#include <vector>

using namespace std;

class Solution 
{
    public:

    long long minCost(long long arr[], long long n)
    {
        // create a min Heap
        priority_queue<long long, vector<long long>, greater<long long> > pq;

        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }
        
        int cost = 0;

        while (pq.size() > 1)
        {
            long long a = pq.top();
            pq.pop();

            long long b = pq.top();
            pq.pop();

            long long sum = (a + b);
            cost += sum;

            pq.push(sum);
        }
        return cost;
    }
};

int main(int argc, char const *argv[])
{
    
    
    return 0;
}
