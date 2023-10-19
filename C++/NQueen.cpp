

#include <iostream>
using namespace std;
void printSolution(int** board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}
bool isSafe(int** board, int row, int col, int N) {
    int i, j;
    for (i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j])
            return false;
    }
    return true;
}
bool solveNQUtil(int** board, int col, int N) {
    if (col >= N) {
        printSolution(board, N);
        return true;
    }
    bool isValid = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;
            isValid = isValid | solveNQUtil(board, col + 1, N);
            board[i][col] = 0;
        }
    }
    return isValid;
}
int main() {
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;
    
    int** board = new int*[N];
    for (int i = 0; i < N; i++) {
        board[i] = new int[N];
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }    
    if (!solveNQUtil(board, 0, N)) {
        cout << "Solution does not exist";
    }    
    return 0;
}