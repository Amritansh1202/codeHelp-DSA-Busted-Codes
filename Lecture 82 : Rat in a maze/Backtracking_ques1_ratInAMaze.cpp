#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isSafe(int newx, int newy, vector<vector<bool> > &vis,  vector<vector<int> > &arr, int n)
{
    if (newx >= 0 && newx < n && newy >= 0 &&newy < n && vis[newx][newy] != 1 && arr[newx][newy] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(int x, int y, vector<vector<int> > &arr, int n, vector<string> &ans, vector<vector<bool> > &vis, string path)
{
    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    
    // 4 movement - D, L, R, U
    vis[x][y] = true;
    // Down - (x+1, y)
    if (isSafe(x + 1, y, vis, arr, n))
    {
        solve(x + 1, y, arr, n, ans, vis, path + 'D');
    }
    
    // left
    if (isSafe(x, y - 1, vis, arr, n))
    {
        solve(x + 1, y, arr, n, ans, vis, path + 'L');
    }

    // right
    if (isSafe(x, y + 1, vis, arr, n))
    {
        solve(x + 1, y, arr, n, ans, vis, path + 'R');
    }

    // up
    if (isSafe(x - 1, y, vis, arr, n))
    {
        solve(x + 1, y, arr, n, ans, vis, path + 'U');
    }
    vis[x][y] = false;
}

vector<string> searchMaze(vector<vector<int> > &arr, int n)
{
    vector<string> ans;
    vector<vector<bool> > visited(n, vector<bool>(n, 0));
    string path = "";

    if (arr[0][0] == 0)
    {
        return;
    }
    

    solve(0,0, arr, n, ans, visited, path);
    return ans;
}

int main(int argc, char const *argv[])
{
    
    
    return 0;
}
