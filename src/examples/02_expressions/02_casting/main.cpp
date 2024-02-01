#include<iostream>
#include "casting.h"

using std::cin; using std::cout;

int main()
{

    auto years = 0;
    auto rate = 1.0;

    cout<<"Enter years: ";
    cin>>years;
    cout<<"Enter rate: ";
    cin>>rate;

    auto result = convert_to_double(years, rate);

    cout<<"Value is: "<<result<<"\n";

    return 0;
}