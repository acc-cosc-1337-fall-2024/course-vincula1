/*
Write double value-return function convert_to_double with an int years and
double interest_rate parameter
*/

double convert_to_double(int years, double rate)
{
    auto result = years * rate;
    return result;
}

/*
Write int value-return function convert_double_to_int with a double parameter
*/

int convert_double_to_int(double num)
{
    return num;
}

/*
Write int value-return function static_cast_double_int with a double parameter
*/

int static_cast_double_int(double num)
{
    auto result = static_cast<int>(num);
    return result;
}