#include <iostream>
#include <string>

std::string region_name;
int num_accidents;
int lowest_accidents = 0;
std::string safest_region;

void getRegInfo(std::string &region, int &accidents);
bool isLower(int accidents, int lowest_accidents);
void showLowest(std::string region, int accidents);

int main(){
    int user_option;
    std::cout << "Please enter in 1 to input the region name and number of accidents" << std::endl;
    std::cout << "Please enter in 0 to quit and show the region with the lowest number of accidents" << std::endl;
    std::cin >> user_option;
    int count = 0;
    
    while (user_option != 0){
        if (user_option != 1){
            std::cout << "Invalid option, please try again." << std::endl;
            std::cout << "Please enter in 1 to input the region name and number of accidents" << std::endl;
            std::cout << "Please enter in 0 to quit and show the region with the lowest number of accidents" << std::endl;
            std::cin >> user_option;
        }
        else{
            getRegInfo(region_name, num_accidents);
            if (lowest_accidents == 0 && count == 0){
                lowest_accidents = num_accidents;
                safest_region = region_name;
                count += 1;
                }
            else if (isLower(num_accidents, lowest_accidents)){
                safest_region = region_name;
                lowest_accidents = num_accidents;
                count += 1;
            }
            std::cout << "Please enter in 1 to input the region name and number of accidents" << std::endl;
            std::cout << "Please enter in 0 to quit and show the region with the lowest number of accidents" << std::endl;
            std::cin >> user_option;
        }
    }

    showLowest(safest_region, lowest_accidents);

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

bool isLower(int accidents, int lowest_accidents){
    if (accidents <= lowest_accidents){
        return true;
    }
    else{
        return false;
    }
}

void showLowest(std::string region, int accidents){
    std::cout << "The region with the lowest reported accidents was: " << region << std::endl;
    std::cout << "The number of accidents for this region was: " << accidents << std::endl;
}