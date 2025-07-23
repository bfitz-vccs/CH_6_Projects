#include <iostream>
#include <string>

std::string region_name;
int num_accidents;

void getRegInfo(std::string &region, int &accidents);
bool isLower(int first_value, int second_value);

int main(){

    getRegInfo(region_name, num_accidents);
    std::cout << "Region name: " << region_name << std::endl;
    std::cout << "Number of accidents: " << num_accidents << std::endl;

    return 0;
}

void getRegInfo(std::string &region, int &accidents){
    std::cout << "Please enter in the region: ";
    std::cin >> region;
    std::cout << "Please enter in the number of accidents for the region: ";
    std::cin >> accidents;

    while (accidents < 0){
        std::cout << "Invalid number of accidents option, please try again." << std::endl;
        std::cout << "Please enter in the number of accidents for the region: ";
        std::cin >> accidents;
        }

}

bool isLower(int first_value, int second_value){
    if (first_value <= second_value){
        return true;
    }
    else{
        return false;
    }
}