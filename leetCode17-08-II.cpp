#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Function to determine the final position of the snake on the grid
    int finalPositionOfSnake(int n, std::vector<std::string>& commands) {
        // Create an n x n grid and initialize it with consecutive integers
        std::vector<std::vector<int>> grid(n, std::vector<int>(n, 0));
        std::vector<std::vector<int>>* ptrGrid = &grid;  // Pointer to the matrix

        // Initialize the grid with values from 0 to n*n-1
        for (int i = 0, val = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                (*ptrGrid)[i][j] = val++;
            }
        }

        // Print the initialized grid
        std::cout << "Initial Grid:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << (*ptrGrid)[i][j] << "  ";
            }
            std::cout << std::endl;
        }

        // Start from the top-left corner of the grid
        int i = 0, j = 0;

        // Traverse the grid based on the commands
        for (const auto& command : commands) {
            if (command == "RIGHT") {
                j = std::min(j + 1, n - 1);  // Move right
            } else if (command == "DOWN") {
                i = std::min(i + 1, n - 1);  // Move down
            } else if (command == "LEFT") {
                j = std::max(j - 1, 0);  // Move left
            } else if (command == "UP") {
                i = std::max(i - 1, 0);  // Move up
            }
        }

        // Return the value at the final position of the snake
        return (*ptrGrid)[i][j];
    }
};

int main() {
    Solution s1;
    std::vector<std::string> commands = {"RIGHT", "RIGHT", "LEFT", "LEFT", "DOWN"};

    // Find the final position value after executing the commands
    int result = s1.finalPositionOfSnake(3, commands);

    std::cout << "Final Position Value: " << result << std::endl;

    return 0;
}

// ************** CODED BY HASSAM FATHE @hassamcoddes *********************** //
