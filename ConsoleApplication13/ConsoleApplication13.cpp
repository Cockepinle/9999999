#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

class MergeSort {
public:
    void Sort(std::vector<int>& arr) {
        if (arr.size() <= 1) {
            return;
        }

        int mid = arr.size() / 2;
        std::vector<int> left(arr.begin(), arr.begin() + mid);
        std::vector<int> right(arr.begin() + mid, arr.end());

        Sort(left);
        Sort(right);
        Merge(arr, left, right);
    }

    void Merge(std::vector<int>& arr, const std::vector<int>& left, const std::vector<int>& right) {
        int i = 0, j = 0, k = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                arr[k++] = left[i++];
            }
            else {
                arr[k++] = right[j++];
            }
        }

        while (i < left.size()) {
            arr[k++] = left[i++];
        }

        while (j < right.size()) {
            arr[k++] = right[j++];
        }
    }
};

int main() {
    std::vector<int> arr(10);

    std::cout << "Введите 10 чисел через enter для сортировки:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cin >> arr[i];
    }

    MergeSort mergeSort;

    auto sortFunc = [&arr, &mergeSort]() {
        mergeSort.Sort(arr);
        };

    std::thread mergeSortThread(sortFunc);

    mergeSortThread.join();

    std::cout << "Сортировка массива:" << std::endl;
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}