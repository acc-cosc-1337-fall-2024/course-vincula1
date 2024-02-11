//write include statements
#include "hwexpressions.h"
#include <iostream>

//write namespace using statement for cout

using namespace std;

int main()
{
	double meal_amount, tip_rate, tip_amount, tax_amount, total;

	cout << "Enter amount for the meal: ";
	cin >> meal_amount;

	tax_amount = get_sales_tax_amount(meal_amount);

	cout << "Enter tip rate: ";
	cin >> tip_rate;

	tip_amount = get_tip_amount(tip_rate, meal_amount);

	total = meal_amount + tax_amount + tip_amount;

	cout << "Meal amount: " << meal_amount << endl;
	cout << "Sales Tax: " << tax_amount << endl;
	cout << "Tip Amount: " << tip_amount << endl;
	cout << "Total: " << total << endl;

	

	return 0;
}
