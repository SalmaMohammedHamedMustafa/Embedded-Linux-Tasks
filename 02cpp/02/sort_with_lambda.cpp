#include <iostream>
#include <algorithm>

constexpr int ascending_order = 1;
constexpr int descending_order = 2;

int main()
{
    int arr[7] = {5, 7, 3, 2, 6, 8, 1};

    auto sort_with_lambda = [](int input_arr[], int output_arr[], int order, size_t size) {
        std::copy(input_arr, input_arr + size, output_arr);
        
        if (order == ascending_order)
        {
            std::sort(output_arr, output_arr + size, [](int a, int b) {
                return a < b;
            });
        }
        else if (order == descending_order)
        {
            std::sort(output_arr, output_arr + size, [](int a, int b) {
                return a > b;
            });
        }
    };

    int ascending_arr[7];
    int descending_arr[7];
    size_t size = sizeof(arr) / sizeof(arr[0]);

    // Sort in ascending order and store in ascending_arr
    sort_with_lambda(arr, ascending_arr, ascending_order, size);
    std::cout << "Array sorted in ascending order: ";
    for (int num : ascending_arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sort in descending order and store in descending_arr
    sort_with_lambda(arr, descending_arr, descending_order, size);
    std::cout << "Array sorted in descending order: ";
    for (int num : descending_arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
