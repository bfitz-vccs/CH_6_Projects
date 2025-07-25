/*
This program takes values from 0 up to and including 20 degrees Fahrenheit and outputs their value in degrees Celsius.
The results are output in a formatted table. 
*/

#include <iostream>
#include <iomanip>

float getCelsius(int temp);
int start_temp = 0;
int end_temp = 20;

int main(){

    std::cout << std::setw(10) << "Fahrenheit" << std::setw(15) << "Celsius" << std::endl;
    std::cout << std::fixed << std::showpoint << std::setprecision(1);
    for (int i = start_temp; i < end_temp + 1; i++){
        std::cout << std::setw(10) << i << std::setw(15) << getCelsius(i) << std::endl;
    }

    return 0;
}

/*
Function: getCelsius
Purpose:
    - Gets the degrees Fahrenheit temp variable as an argument and calculates and returns its value in degrees Celsius. 
Parameters:
    - int temp: the temperature in degrees Fahrenheit.
Returns:
    - This function returns the float value from the result of a formula converting degrees Fahrenheit to degrees Celsius.
Preconditions:
    - None
Postconditions:
    - Ensures that the calculation from the argument in the formula is returned as a float.
Side Effects: 
    - None
*/
float getCelsius(int temp){
    return (5 * (temp - 32)) / 9.0;
}