#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cout << "\nSimple Array" << endl;

	int iarray[5] = { 0, 1, 2, 3, 4 };
	bool barr[10] = { false };

	char carr[4];
	carr[0] = 'a';
	carr[1] = 'b';
	carr[3] = 'd';
	carr[4] = 'c';

	char c = carr[4];

	const int n = 10;
	int array[n];
	for(int i = 10; i > 0; i--){
		int index = 10 - i;
		array[index] = i;
	}

	cout << "Unsorted array: " << endl;
	for(int i = 0; i < n; i++){
		cout << "Index " << i << " holds the number " << array[i] << ".\n";
	}

	sort(array, array + n);

	cout << "Sorted array: " << endl;
	for(int i = 0; i < n; i++)
		cout << "Index " << i << " holds the number " << array[i] << ".\n";

	return 0;
}