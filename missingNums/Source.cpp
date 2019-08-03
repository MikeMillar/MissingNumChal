#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

// For a random range of 1-500, find any missing numbers

// Fill vector
void fillVector(vector<int>& nums) {
	for (int i = 1; i < 501; i++) {
		nums.push_back(i);
	}
}

// Splice numbers
void spliceVector(vector<int>& nums) {
	int spliceNum = 5;
	for (int i = 0; i < spliceNum; i++) {
		int r = rand() % nums.size() - 1;
		cout << "Spliced number: " << nums[r] << ", " << nums[r+1] << ", " << nums[r+2] << ", " << nums[r+3] << endl;
		nums.erase(nums.begin() + r);
		nums.erase(nums.begin() + r);
		nums.erase(nums.begin() + r);
		nums.erase(nums.begin() + r);
	}
}

// Find missing numbers
void findMissing(vector<int>& nums, vector<int>& missing) {
	// Set number expected var and index
	int e = 1; // Independtant variable we can control seperate from loop
	int index = 0; // Moves through vector

	// Loop through array comparing expected val to array value	
	while (index < nums.size()) {
		if (e != nums[index]) {
			missing.push_back(e); // If num missing, adds to array
			e++; // If no match, does not move index, but moves expected up
		}
		else { // If match, moves to next index, and adds number to expected value
			index++;
			e++;
		}
	}
}

// Print missing values
void printMissing(vector<int>& missing) {
	cout << "Missing numbers: " << flush;
	for (int i = 0; i < missing.size(); i++) {
		if (missing[i] != missing.back()) {
			cout << missing[i] << ", " << flush;
		}
		else {
			cout << missing[i] << endl;
		}
	}
}

int main() {
	// Initialize random
	srand(time(NULL));

	// Create vectors
	vector<int> numbers;
	vector<int> missing;

	// Fill vector of nums
	fillVector(numbers);

	// Splice numbers
	spliceVector(numbers);

	// Find missing values
	findMissing(numbers, missing);

	// Print missing values
	printMissing(missing);
	

	//End Program
	cout << "Program ending..." << endl;

	return 0;
}