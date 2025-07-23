#include <iostream>
#include <iomanip>

float getCelsius(int temp);
int start_temp = 0;
int end_temp = 20;

int main(){

    std::cout << std::setw(10) << "Fahrenheit" << std::setw(15) << "Celsius" << std::endl;
    std::cout << std::fixed << std::showpoint << std::setprecision(2);
    for (int i = start_temp; i < end_temp; i++){
        float celsius = getCelsius(i);
        std::cout << std::setw(10) << i << std::setw(15) << celsius << std::endl;
    }

    return 0;
}

float getCelsius(int temp){
    float temp_celsius = (5 * (temp -32)) / 9;
    return temp_celsius;
}