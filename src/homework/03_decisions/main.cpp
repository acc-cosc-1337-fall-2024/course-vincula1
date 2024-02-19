//write include statements
#include "decisions.h"
#include <iostream>

int main() 
{
	int option, grade;
	std::cout << "MAIN MENU\n\n1-Get grade using if\n2-Get grade using switch\n3-Exit\nEnter choice: ";
	std::cin >> option;

	switch (option) {
		case 1:
		case 2:
			std::cout << "Enter a grade (0-100):  ";
			std::cin >> grade;
			if (grade < 0 || grade > 100) {
				std::cout << "Number is out of range, please put in a valid one.\n";
			} else {
				std::string result = (option == 1) ? get_letter_grade_using_if(grade) : get_letter_grade_using_switch(grade);
				std::cout << "Letter grade: " << result << std::endl;
			}
			break;
		
		case 3:
			std::cout << "Exiting the menu\n";
			break;
		default:
			std::cout << "Tthis is an invalid option, please try again.";
	}

	return 0;
}