#include <iostream>
#include <vector>

using namespace std;

int main() {
    // read in the matrix
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    
    cout << "Enter the elements of the matrix: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    // row with the largest element
    int max_row = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] > matrix[max_row][0]) {
                max_row = i;
            }
        }
    }

    // column with the smallest element
    int min_col = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] < matrix[0][min_col]) {
                min_col = j;
            }
        }
    }

    // scalar product of the row and column
    int result = 0;
    for (int j = 0; j < m; j++) {
        result += matrix[max_row][j] * matrix[j][min_col];
    }

    cout << "max row: " << max_row << endl;
    cout << "min col: " << min_col << endl;
    cout << "scalar product row * col: " << result << endl;

    return 0;
}