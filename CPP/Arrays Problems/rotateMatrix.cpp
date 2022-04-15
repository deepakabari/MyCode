#include<bits/stdc++.h>
void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int row = 0, col = 0;
    int previous, current;
    while(row < n && col < m){
		if(row == n - 1 || col == m - 1){
			break;
        }
        previous = mat[row+1][col];
        for(int i=col; i<m; i++){
			current = mat[row][i];
            mat[row][i] = previous;
            previous = current;
        }
        row++;
        for(int i=row; i<n; i++){
			current = mat[i][m-1];
            mat[i][m-1] = previous;
            previous = current;
        }
        m--;
        if(row <n){
			for(int i=m-1; i>=col; i--){
                current = mat[n-1][i];
                mat[n-1][i] = previous;
                previous = current;
            }
        }
        n--;
        if(col < m){
			for(int i=n-1; i>=row; i--){
				current = mat[i][col];
                mat[i][col] = previous;
                previous = current;
            }
        }
       col++;
    }		


}