#include <iostream>
#include <iomanip>
using namespace std;

void PrintArray (int ArrayName[], const int ArraySize);
void BubbleSort(int ArrayName[], const int ArraySize);

int main(){
	const int ArraySize = 10;
	int Array1[ArraySize] = {10,9,8,7,6,5,4,3,2,1};

	cout << "Before Sorting:" << endl;
	PrintArray(Array1,ArraySize);
	BubbleSort (Array1,ArraySize);
	cout << "\nAfterSorting:" << endl;
	PrintArray(Array1,ArraySize);

	return 0;
}

void BubbleSort(int ArrayName[] , const int ArraySize){
	int Temp; 
	bool IsFound = false;

	for (int i = 1 ; i < ArraySize ; i++){
		for (int j = 0; j < ArraySize - i ; j++){
			if (ArrayName[j] > ArrayName[j+1]){
				Temp = ArrayName[j];
				ArrayName[j] = ArrayName[j+1];
				ArrayName[j+1] = Temp;

				IsFound = true;
			}
		}
		if (!IsFound)
			break;
	}
}

void PrintArray (int ArrayName[] , const int ArraySize){
	cout << setiosflags(ios::left);
	for (int i = 0 ; i < ArraySize ; i++){
		cout << setw(3) << ArrayName[i];
		if (i+1 % 20 == 0)
			cout << endl;
	}
	cout << endl;
}