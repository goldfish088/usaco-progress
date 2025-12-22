#include <bits/stdc++.h>
using namespace std;

bool can_place(array<string, 8>& board, int col, int row) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == 'q') {
                // up/down and left/right
                if (row == i || col == j) return false;

                // diagonals
                if (abs(row - i) == abs(col - j)) return false;
            }
        }
    }
    return board[row][col] != '*';
}

long long backtrack(array<string, 8>& board, int row = 0) {
    if (row == 8) return 1;

    long long ans = 0;

    for (int col = 0; col < 8; ++col) {
        if (!can_place(board, col, row)) continue;

        board[row][col] = 'q';
        ans += backtrack(board, row+1);
        board[row][col] = '.';
    }

    return ans;
}

int main(void) {
    array<string, 8> board;
    for (int i = 0; i < 8; ++i) cin >> board[i];

    cout << backtrack(board) << endl;
}
