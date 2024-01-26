#include <iostream>

//write include statements
#include "data_types.h"

//write namespace using statement for cout
using std::cout;
using std::cin;


int main()
{
	int num = 0;

	cout<<"Enter a number: ";
	cin>>num;
	
	int result = 0;
	result = multiply_numbers(num);

	cout<<"Value is: "<<result<<"\n";

	int num1 = 4;
	result = multiply_numbers(num1);

	cout<<"Value is: "<<result<<"\n";

	return 0;
}
