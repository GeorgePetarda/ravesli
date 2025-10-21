#include <iostream>
#include <vector>

using namespace std;

int iterationBinarySearch(int min, int max, vector <int> &a, int target) {
	while (min <= max) {
		int mid = (min + max) / 2;
		if (a[mid] > target) {
			max = mid - 1;
		}
		else if (a[mid] < target) {
			min = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

int recurentBinarySearch(int min, int max, vector <int>& a, int target) {
	if (min > max) {
		return -1;
	}
	int mid = (min + max) / 2;
	if (a[mid] > target) {
		return recurentBinarySearch(min, mid - 1, a, target);
	}
	else if (a[mid] > target) {
		return recurentBinarySearch(mid + 1, max, a, target);
	}
	else {
		return mid;
	}
}

int main() {
	int N; cin >> N;
	vector <int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	int target; cin >> target;
	cout << "1. Iteration binary search" << endl;
	cout << "2. Recurent binary search" << endl;
	int request;
	cin >> request;
	switch (request) {
		case 1:
			cout << iterationBinarySearch(0, N - 1, a, target) + 1;
			break;
		case 2:
			cout << recurentBinarySearch(0, N - 1, a, target) + 1;
			break;
	}
}