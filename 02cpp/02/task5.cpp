#include <iostream>

void findEvenAndOdd(int array[], int size, int evenArray[], int& evenCount, int oddArray[], int& oddCount) {
    evenCount = 0;
    oddCount = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] % 2 == 0) {
            evenArray[evenCount++] = array[i];
        } else {
            oddArray[oddCount++] = array[i];
        }
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(array) / sizeof(array[0]);
    int evenArray[size]; // Worst case, all elements are even
    int oddArray[size];  // Worst case, all elements are odd
    int evenCount = 0;
    int oddCount = 0;

    findEvenAndOdd(array, size, evenArray, evenCount, oddArray, oddCount);

    std::cout << "Even numbers: ";
    for (int i = 0; i < evenCount; ++i) {
        std::cout << evenArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Odd numbers: ";
    for (int i = 0; i < oddCount; ++i) {
        std::cout << oddArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
