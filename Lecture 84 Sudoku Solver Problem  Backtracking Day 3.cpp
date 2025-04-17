//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9


// } Driver Code Ends
class Solution { // https://www.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1
	private:
		bool isSafe(int val, int grid[N][N], int row, int col) {
			for(int i = 0; i < 9; i++) {
				if(grid[row][i] == val) {
					return false;
				}

				if(grid[i][col] == val) {
					return false;
				}

				if(grid[3*(row/3) + i/3][3*(col/3) + i%3] == val) {
					return false;
				}
			}

			return true;
		}
	public:
		//Function to find a solved Sudoku.
		bool SolveSudoku(int grid[N][N]) {
			int n = 9;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {

					if(grid[i][j] == 0) {

						for(int val = 1; val <= 9; val++) {

							if(isSafe(val, grid, i, j)) {

								grid[i][j] = val;

								bool nextSolutionPossible = SolveSudoku(grid);

								if(nextSolutionPossible) {
									return true;
								} else {
									grid[i][j] = 0;
								}
							}
						}

						return false;
					}

				}
			}

			return true;
		}

		//Function to print grids of the Sudoku.
		void printGrid (int grid[N][N]) {
			bool isPossible = SolveSudoku(grid);
			if(isPossible) {
				for(int i = 0; i < 9; i++) {
					for(int j = 0; j < 9; j++) {
						cout<<grid[i][j]<<" ";
					}
				}
			} else {
				cout<<"No solution exists";
			}
		}
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--) {
		int grid[N][N];

		for(int i=0; i<9; i++)
			for(int j=0; j<9; j++)
				cin>>grid[i][j];

		Solution ob;

		if (ob.SolveSudoku(grid) == true)
			ob.printGrid(grid);
		else
			cout << "No solution exists";

		cout<<endl;
	}

	return 0;
}
// } Driver Code Ends
