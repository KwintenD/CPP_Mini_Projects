int BinarySearch(const int * sortedArray, int size, int target);

int main() {
	int sortedArray[10]{ 1,3,7,9,11,13,15,17,19,21 };
	int positionInArray = BinarySearch(sortedArray, sizeof(sortedArray) / sizeof(int), 7);

	return 0;
}

int BinarySearch(const int * sortedArray, int size, int target) {
	int low{}, high{ size - 1 };

	while (low <= high) {
		int mid = (low + high) / 2;
		int guess = sortedArray[mid];

		if (guess == target) return mid;
		else if (guess < target) low = mid + 1;
		else high = mid - 1;
	}

	return -1;
}
