#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <heap>

using namespace std;

int kthSmallest(int arr[], int l, int r, int k)
{
    // STEP 1
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    // STEP 2
    for (int i = k; i < r; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
        
    }
    // STEP 3:
    int ans = pq.top();
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}

