#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution 
{
    public:

    void heapify(vector<int> &arr, int n, int i)
    {   
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if (left < n && arr[largest] < arr[left])
        {
            largest = left;
        }
        if (right < n && arr[largest] < arr[right])
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }

    }   

    vector <int> mergeHeaps(vector<int> &a, vector<int> &b)
    {
        // step 1 : merge both arrays into one

        vector<int> ans;
        copy(a.begin(), a.end(), back_inserter(ans));
        copy(b.begin(), b.end(), back_inserter(ans));


        // step 2 : nuild heap using merged array
        int n = ans.size();
        for (int i = n/2 - 1; i >= 0; i--)
        {
            heapify(ans, n, i); 
        }
    return ans;   
    }
};

int main(int argc, char const *argv[])
{
    
    
    return 0;
}
