#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int row, int col, vector<vector<int> > &board, int value)
{
    for (int i = 0; i < board.size(); i++)
    {
        // row check
        if (board[row][i] == value)
        {
            return false;
        }
        // col check
        if (board[i][col] == value)
        {
            return false;
        }
        // check 3x3 matrix
        if (board[3*(row/3) + i/3][3*(col/3) + i%3] ==  value)
        {
            return false;
        }
    }
    
    return true;
}

bool solve(vector<vector<int> >& board)
{
    int n = board[0].size(); // row and col size

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // cell empty
            if (board[row][col] == 0)
            {
                // cell empty hai mtlb ek value daalni tru kr skte hain
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(row, col, board, val))
                    {
                        board[row][col] = val;
                        // recursive call
                        bool aageSolutionPossible = solve(board);
                        if (aageSolutionPossible)
                        {
                            return true;
                        }
                        else
                        {
                            // backtrack
                            board[row][col] = 0;
                        }
                        
                    }
                    
                }
                
                // koi value possible nhi hai
                return false;
            }
            
        }
        
    }
    return true;
}

void solveSudoku(vector<vector<int> > &sudoku)
{
    solve(sudoku);
}

int main(int argc, char const *argv[])
{
    
    
    return 0;
}
