#include <iostream>
#include <vector>
#include <ctime>

std::vector<int> cocktail(std::vector<int> vector) {
    bool swap = true;
    while (swap) {
        swap = false;
        for (int i = 0; i <= vector.size() - 2; i++) {
            if (vector[i] > vector[i + 1]) {
                swap = true;
                std::swap(vector[i], vector[i + 1]);
            }
        }
        for (int i = vector.size() - 2; i > 0; i--) {
            if (vector[i] < vector[i - 1]) {
                swap = true;
                std::swap(vector[i], vector[i - 1]);
            }
        }
    }
    return vector;
}

std::vector<int> quick(std::vector<int> vector, int left = 0, int right = -1)
{
    if (right = -1) right = vector.size() - 1;
    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = vector[left];
    while (left < right)
    {
        while ((vector[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            vector[left] = vector[right];
            left++;
        }
        while ((vector[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            vector[right] = vector[left];
            right--;
        }
    }
    vector[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        vector = quick(vector, left, pivot - 1);
    if (right > pivot)
        vector = quick(vector, pivot + 1, right);
    return vector;
}

int main() {
    std::srand(std::time(nullptr));
    std::vector<int> arr;
    for (int i = 0; i <= 30; i++) {
        int random = std::rand() % 201 - 100;
        arr.push_back(random);
        std::cout << random << " ";
    }
    std::cout << std::endl;
    std::vector<int> sorted1 = cocktail(arr);
    for (int i : sorted1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::vector<int> sorted2 = quick(arr);
    for (int i : sorted2) {
        std::cout << i << " ";
    }
    return 0;
    // не осилил bitonic sort, попробую дома доделать
}
