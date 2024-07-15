#include <iostream>

/*
merge two array in another array
@param first array , it's size, the second array, its size, the merged array
*/
void mergeArrays(int array1[], int size1, int array2[], int size2, int result[]) {
    // Copy elements from the first array into the result array
    for (int i = 0; i < size1; ++i) {
        result[i] = array1[i];
    }
    
    // Copy elements from the second array into the result array
    for (int i = 0; i < size2; ++i) {
        result[size1 + i] = array2[i];
    }
}

int main() {
    int array1[] = {1, 3, 5};
    int array2[] = {2, 4, 6};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int mergedArray[size1 + size2];

    mergeArrays(array1, size1, array2, size2, mergedArray);

    std::cout << "Merged array: ";
    for (int i = 0; i < size1 + size2; ++i) {
        std::cout << mergedArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
