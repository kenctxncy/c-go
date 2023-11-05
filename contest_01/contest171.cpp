#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> heights[i];
    }

    std::vector<int> left_max(n, 0);
    std::vector<int> right_max(n, 0);

    int max_left = 0;
    for (int i = 0; i < n; i++) {
        left_max[i] = max_left;
        max_left = std::max(max_left, heights[i]);
    }

    int max_right = 0;
    for (int i = n - 1; i >= 0; i--) {
        right_max[i] = max_right;
        max_right = std::max(max_right, heights[i]);
    }

    int total_water = 0;
    for (int i = 0; i < n; i++) {
        int trapped_water = std::min(left_max[i], right_max[i]) - heights[i];
        if (trapped_water > 0) {
            total_water += trapped_water;
        }
    }

    std::cout << total_water << std::endl;

    return 0;
}
