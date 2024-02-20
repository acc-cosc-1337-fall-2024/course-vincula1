//write include statements
#include <iostream>
#include "repetition.h"

using namespace std;

//write using statements

int main() {
	int choice;
	do {
		cout << "1-Use Factorial Function\n2-Use GCD Function\n3-Exit\nEnter your choice here: ";
		cin >> choice;
		if (choice == 1) {
			int num;
			cout << "Enter a number ";
			cin >> num;
			cout << "Factorial: " << factorial(num) << endl;
		} else if (choice == 2) {
			int num1, num2;
			cout << "Enter two numbers (Has to be formatted like- 15 5):" ;
			cin >> num1 >> num2;
			cout << "GCD: " << gcd(num1, num2) << endl;
		} else if (choice == 3) {
			char confirm;
			cout << "Are you sure you want to exit? :3 (Reply with Y for yes)";
			cin >> confirm;
			if (confirm == 'Y') {
				break;
			}
		}
	} while (true);

	return 0;
}
