/*
This program prompts the user to enter in region names and the number of accidents for these regions.
The program will stop prompting the user for input when they choose the quit option.
After the quit option is chosen, the region with the lowest number of accidents is printed alongside descriptive text.
*/

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
/*
Function: getRegInfo
Purpose:
    - Gets the region and accidents values as input from the user and assigns them by reference to the associated variables. 
Parameters:
    - string &region: the name of the region.
    - int &accidents: the number of accidents for the region.
Returns:
    - This function does not return anything (i.e. it's void), although it does assign values to the arguments passed by reference
Preconditions:
    - None
Postconditions:
    - Ensures that the passed by reference region and accidents values are assigned to variables.
    - It also ensures that the value for accidents is positive by prompting the user to enter in a new value if it is negative.
Side Effects: 
    - None
*/
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
/*
Function: isLower
Purpose:
    - Evaluates if the first argument is lower than the second argument, and returns true or false accordingly. 
Parameters:
    - int accidents: the number of accidents for a region.
    - int lowest_accidents: the current number of accidents for the region with the lowest number of accidents.
Returns:
    - This function returns true if accidents is less than or equal to lowest_accidents and false if it is not.
Preconditions:
    - None
Postconditions:
    - Ensures that either true or false is returned depending on the evaluation.
Side Effects: 
    - None
*/
bool isLower(int accidents, int lowest_accidents){
    if (accidents <= lowest_accidents){
        return true;
    }
    else{
        return false;
    }
}

/*
Function: showLowest
Purpose:
    - Outputs the values for the safest region and the corresponding number of accidents for this region. 
Parameters:
    - string region: the name of the region.
    - int accidents: the number of accidents for the region.
Returns:
    - This function does not return anything but it does output the argument values alongside descriptive text.
Preconditions:
    - None
Postconditions:
    - Ensures that the argument values are printed with descriptive text.
Side Effects: 
    - None
*/
void showLowest(std::string region, int accidents){
    std::cout << "The region with the lowest reported accidents was: " << region << std::endl;
    std::cout << "The number of accidents for this region was: " << accidents << std::endl;
}