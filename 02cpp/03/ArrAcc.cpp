#include <iostream>
#include <vector>
#include <numeric>  // Required for std::accumulate

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // Calculate the sum of the vector elements
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum of the array elements is: " << sum << std::endl;

    return 0;
}
