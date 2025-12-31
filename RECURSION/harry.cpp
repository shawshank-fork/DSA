#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>

using namespace std;

const vector<pair<int, int>> king_moves = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
};

const vector<pair<int, int>> rook_moves = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

const vector<pair<int, int>> bishop_moves = {
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};

const vector<pair<int, int>> knight_moves = {
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, 
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1}
};

const vector<vector<pair<int, int>>> piece_moves = {
    king_moves,      // 0: King
    rook_moves,      // 1: Rook
    bishop_moves,    // 2: Bishop
    rook_moves + bishop_moves, // 3: Queen (combination of rook and bishop)
    knight_moves     // 4: Knight
};

// Function to check if the position is valid
bool is_valid(int x, int y, int n, int m, const vector<string>& board) {
    return (x >= 0 && x < n && y >= 0 && y < m && board[x][y] != '#');
}

// BFS to find the minimum moves
int bfs(int n, int m, int k, const vector<string>& board, pair<int, int> start, pair<int, int> end) {
    // Initial state: (x, y, piece_type, transformations, moves)
    queue<tuple<int, int, int, int, int>> q; // (x, y, piece type, transformations, moves)
    set<tuple<int, int, int, int>> visited; // (x, y, piece type, transformations)

    q.emplace(start.first, start.second, 0, 0, 0); // Start with King
    visited.emplace(start.first, start.second, 0, 0);

    while (!q.empty()) {
        auto [x, y, piece, transformations, moves] = q.front();
        q.pop();

        // Check if we reached the exit
        if (make_pair(x, y) == end) {
            return moves;
        }

        // Try moving with the current piece
        for (const auto& [dx, dy] : piece_moves[piece]) {
            if (piece == 1 || piece == 2 || piece == 3) {
                // Rook, Bishop, Queen can move multiple steps
                int nx = x + dx, ny = y + dy;
                while (is_valid(nx, ny, n, m, board)) {
                    if (make_pair(nx, ny) == end) {
                        return moves + 1;
                    }
                    if (visited.emplace(nx, ny, piece, transformations).second) {
                        q.emplace(nx, ny, piece, transformations, moves + 1);
                    }
                    nx += dx;
                    ny += dy;
                }
            } else {
                // King and Knight can only move one square
                int nx = x + dx, ny = y + dy;
                if (is_valid(nx, ny, n, m, board)) {
                    if (make_pair(nx, ny) == end) {
                        return moves + 1;
                    }
                    if (visited.emplace(nx, ny, piece, transformations).second) {
                        q.emplace(nx, ny, piece, transformations, moves + 1);
                    }
                }
            }
        }

        // Try transforming to another piece if we haven't exhausted K transformations
        if (transformations < k) {
            for (int new_piece = 0; new_piece < 5; ++new_piece) {
                if (new_piece != piece) {
                    if (visited.emplace(x, y, new_piece, transformations + 1).second) {
                        q.emplace(x, y, new_piece, transformations + 1, moves);
                    }
                }
            }
        }
    }

    return -1; // If we can't reach the exit
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<string> board(N);
    pair<int, int> start, end;

    // Read the board and locate the start and end positions
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
        for (int j = 0; j < M; ++j) {
            if (board[i][j] == 'B') {
                start = {i, j};
            } else if (board[i][j] == 'P') {
                end = {i, j};
            }
        }
    }

    // Execute BFS to find the minimum moves
    int min_moves = bfs(N, M, K, board, start, end);
    cout << min_moves << endl;

    return 0;
}
