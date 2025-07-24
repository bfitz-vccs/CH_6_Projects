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

float getCelsius(int temp){
    return (5 * (temp - 32)) / 9.0;
}