#include <iostream>
#include<random>

using namespace std;

void displayRun(int values[], int size);
bool hasRun(int values[], int size);
int rollDice();

int main() {

	int const arraySize = 20;
	int randArray[arraySize];

	srand(time(0));

	do {
		for (int i = 0; i < arraySize; i++) {
			randArray[i] = rollDice();
		}
		displayRun(randArray, arraySize);
		cout << endl;
	} while (!hasRun(randArray, arraySize));

	return 0;	
}

void displayRun(int values[], int size) {
	int parenthHold = values[0];
	bool continueRun = false;
	
	for (int i = 1; i < size + 1; i++) {
		if (continueRun) {
			if (values[i] == parenthHold) {
				cout << parenthHold;
			}
			else {
				cout << parenthHold << ")";
				continueRun = false;
			}
		}
		else {
			if (values[i] == parenthHold) {
				cout << "(" << parenthHold;
				continueRun = true;
			} else {
				cout << parenthHold;
			} 
		}
		parenthHold = values[i];
		cout << " ";
	}
}

bool hasRun(int values[], int size) {
	int parenthHold = values[0];
	for (int i = 1; i < size + 1; i++) {
		if (values[i] == parenthHold) {
			return true;
		}
		parenthHold = values[i];
	}
	return false;
}

int rollDice() {
	return rand() % 6 + 1;
}