#include <iostream>
#include <string>
#include "func.h"

int main() {
	int choice;
	std::string dna;

	do {
		std::cout << "Menu\n";
		std::cout << "1- Get GC Content\n";
		std::cout << "2- Get DNA Compliment\n";
		std::cout << "3- Exit\n";
		std::cin >> choice;

		switch (choice) {
			case 1:
				std::cout << "Enter DNA Sequence: ";
				std::cin >> dna;
				std::cout << "GC Contennt: " << get_gc_content(dna) << "\n";
				break;
			case 2:
				std::cout << "Enter DNA Sequence: ";
				std::cin >> dna;
				std::cout << "DNA Compliment: " << get_dna_compliment(dna) << "\n";
				break;
			case 3:
				std::cout << "Exiting...";
				break;
			default:
				std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";

		}

	} while(choice != 3);


	return 0;
}
