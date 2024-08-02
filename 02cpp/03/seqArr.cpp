#include <iostream>
#include <vector>
#include <numeric>  // For std::iota

int main() {
    const int start = 10;
    const int end = 10000;

    // Calculate the size of the array needed
    int size = end - start + 1;
    // Create a vector of the calculated size
    std::vector<int> numbers(size);
    // Fill the vector with sequential numbers starting from 'start'
    std::iota(numbers.begin(), numbers.end(), start);
    //print the vector to verify contents
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    return 0;
}
