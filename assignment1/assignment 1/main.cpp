/*
Kalvin Tran
CS-303 Assignment 1
09/09/2023
*/



#include "functions.h"

void find(int target, int arr[], int arrSize) {
	if (arrSize <= 0) { //check to see if array has a size
		cout << "Error: Array does not have a size." << endl;
	}

	bool trig = false;
	for (int i = 0; i < arrSize; ++i) {
		if (target == arr[i]) { //checks if number is at index
			cout << "The number " << target << " is at index " << i << "." << endl;
			trig = true;
			break;
		}
	}
	if (!trig) {
		cout << "The number " << target << " is not found in the array." << endl;
	}
}

int modify(int index, int newVal, int arr[], int arrSize) {
	try {
		if (arrSize <= 0) { //check to see if array has a size
			throw invalid_argument("Error: Array does not have a size.\n");
		}
		int old = arr[index];
		if (arr[index] == old) { //replaces old val with new val
			arr[index] = newVal;
			cout << "Old value was: " << old << "\nNew value is: " << newVal << endl;
			return 0;
		}
		else {
			throw out_of_range("Could not perform action.\n"); //cout if action cannot be performed
		}
	}
	catch (const exception& ex) {
		cerr << "Exception: " << ex.what() << endl;
		return -1;
		}
}

void add(int val, int arr[], int arrSize) {
	try {
		if (arrSize <= 0) { //check to see if array has a size
			throw invalid_argument("Error: Array does not have a size.");
		}
		for (int i = 0; i < arrSize - 1; ++i) { //shifts array one index left
			arr[i] = arr[i + 1];
		}
		arr[arrSize - 1] = val;
		cout << "New Array: ";
		for (int i = 0; i < arrSize; ++i) {
			cout << arr[i] << " ";
		}
	}
	catch (const exception& ex) {
		cerr << "Exception: " << ex.what() << endl;
	}
}

void removeIndex(int index, int arr[], int arrSize) {
	if (arrSize <= 0) { //check to see if array has a size
		cout << "Error: Array does not have a size." << endl;
	}
	arr[index] = 0;
	cout << "New Array: ";
	for (int i = 0; i < arrSize; ++i) {
		cout << arr[i] << " ";
	}
}

int main() {
	const int length = 10;
	int integers[length], userInput, input, index;
	int size = sizeof(integers) / sizeof(integers[0]);

	ifstream inFile;
	inFile.open("text.txt");
	if (!inFile.is_open()) {
		cout << "File not found\n";
		return -1;
	}

	for (int i = 0; i < length; ++i) {
		inFile >> integers[i];
	}

	//  MAIN MENU
	cout << "Current Array: ";
	for (int i = 0; i < size; ++i) {
		cout << integers[i] << " ";
	}
	cout << "\n\nWhat would you like to do?\n\n 1 - Check Number\n 2 - Modify Number\n 3 - Add Number\n 4 - Remove Number from Index" << endl;
	cin >> userInput;
	while (true) {
		switch (userInput) {
		case 1:
			cout << "What number would you like to find?" << endl;
			cin >> input;
			find(input, integers, size);
			break;
		case 2:
			cout << "What index would you like to modify?" << endl;
			cin >> index;
			cout << "What number do you want to put there?" << endl;
			cin >> input;
			modify(index, input, integers, size);
			cout << "New Array: ";
			for (int i = 0; i < size; ++i) {
				cout << integers[i] << " ";
			}
			break;
		case 3:
			cout << "What number do you want to add to the end of the array?\n *will delete element at first index" << endl;
			cin >> input;
			add(input, integers, size);
			break;
		case 4:
			cout << "What index do you want to remove?" << endl;
			cin >> input;
			removeIndex(input, integers, size);
			break;
		default:
			cout << "Input invalid";
			break;
		}
		return -1;
	}
}

