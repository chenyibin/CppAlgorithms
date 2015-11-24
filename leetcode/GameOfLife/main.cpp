#include <iostream>
#include <vector>

class Solution {
    size_t m_dim_x;
    size_t m_dim_y;
    size_t m_max_x;
    size_t m_max_y;
public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
        board = board;

        m_dim_x = board.size();
        m_dim_y = board[0].size();

        m_max_x = m_dim_x - 1;
        m_max_y = m_dim_y - 1;
        for (auto y = 0; y < m_dim_y; ++y) {
            for (auto x = 0; x < m_dim_x; ++x) {
                update(board, x, y);
            }
        }
        for (auto y = 0; y < m_dim_y; ++y) {
            for (auto x = 0; x < m_dim_x; ++x) {
                board[x][y] >>= 1;
            }
         }

    }
private:
    void update(std::vector<std::vector<int>>& board, const size_t& x, const size_t& y)
    {
        size_t alive_neighbors = 0;
        size_t y_minus = 0;
        size_t y_plus = 0;
        if (x > 0) {
            size_t x_minus = x - 1;
            if (y > 0) {
                y_minus = y - 1;
                // check x_minus, y_minus
                if (board[x_minus][y_minus] & 1 == 1)
                {
                    ++alive_neighbors;
                }
            }
            // check x_minus, y
            if (board[x_minus][y] & 1 == 1) {
                ++alive_neighbors;
            }

            if (y < m_max_y) {
                y_plus = y + 1;
                // check x_minus, y_plus
                if (board[x_minus][y_plus] == 1) {
                    ++alive_neighbors;
                }
            }
        }

        if (x < m_max_x) {
            size_t x_plus = x + 1;

            if (y > 0) {
                y_minus = y - 1;
                // check x_plus, y_minus
                if (board[x_plus][y_minus] & 1 == 1) {
                    ++alive_neighbors;
                }
            }
            // check x_plus, y
            if (board[x_plus][y] == 1) {
                ++alive_neighbors;
            }

            if (y < m_max_y) {
                // check x_plus, y_plus
                y_plus = y + 1;
                if (board[x_plus][y_plus] == 1) {
                    ++alive_neighbors;
                }
            }
        }

        // check x, y_plus
        if ((y > 0) && board[x][y_minus] & 1 == 1) {
            ++alive_neighbors;
        }

        // check x, y_plus
        if ((y < m_max_y) && board[x][y_plus] == 1) {
            ++alive_neighbors;
        }

        if (alive_neighbors == 2) {
            if (board[x][y] == 1) {
                board[x][y] = 3;
            }
        } else if (alive_neighbors == 3) {
            board[x][y] |= 2;
        }
    }

};

int main() {
    std::vector<std::vector<int>> board;
    board.emplace_back(std::vector<int>{1,1});
    board.emplace_back(std::vector<int>{1,0});
    Solution solution;
    solution.gameOfLife(board);

    for (auto row : board) {
        std::cout << '[';
        bool first = true;
        for (auto col : row) {
            if (first) first = false;
            else std::cout << ',';
            std::cout << col;
        }
        std::cout << ']';
    }
    return 0;
}