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
	if (right == -1) right = vector.size() - 1;
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

std::vector<int> swap(std::vector<int> vector, int i, int j, int dir)
{
	if (dir == (vector[i] > vector[j]))
		std::swap(vector[i], vector[j]);
	return vector;
}

std::vector<int> merge(std::vector<int> vector, int low, int cnt, int dir)
{
	if (cnt > 1)
	{
		int k = cnt / 2;
		for (int i = low; i < low + k; i++)
			vector = swap(vector, i, i + k, dir);
		vector = merge(vector, low, k, dir);
		vector = merge(vector, low + k, k, dir);
	}
	return vector;
}

std::vector<int> bitonic(std::vector<int> vector, int low = 0, int cnt = -1, int dir = 1)
{
	if (cnt == -1) cnt = vector.size();
	if (cnt > 1)
	{
		int k = cnt / 2;
		vector = bitonic(vector, low, k, 1);
		vector = bitonic(vector, low + k, k, 0);
		vector = merge(vector, low, cnt, dir);
	}
	return vector;
}

int main() {
	std::srand(std::time(nullptr));
	std::vector<int> arr;
	for (int i = 0; i <= 31; i++) {
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
	std::cout << std::endl;
	std::vector<int> sorted3 = bitonic(arr);
	for (int i : sorted3) {
		std::cout << i << " ";
	}
	return 0;
}
