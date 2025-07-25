/*
This program prompts the user to enter in information about the specifications for a painting job.
It then produces a cost estimate based on the user input which is broken down by components.
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int getRooms();
float getSqFt();
int gallonsForRoom(float SqFt);
float getPricePerGallon();
void displayEstimate(float paint_cost, int gallons, float labor_cost, float labor_hours);

float gallonsPerSqFt = 1 / 110.0;
float laborPerSqFt = 8 / 110.0;
float laborChargePerHour = 25.00;
int gallonsNeeded = 0;
float paintCharge = 0;
float labor;
float laborHours = 0;
float laborCharge = 0;


int main(){
    int numRooms = getRooms();
    for (int i = 0; i < numRooms; i++){
        float squareFeet = getSqFt();
        int gallons = gallonsForRoom(squareFeet);
        gallonsNeeded += gallons;
        float paintPrice = getPricePerGallon();
        paintCharge += gallons * paintPrice;
        labor = squareFeet * laborPerSqFt;
        laborHours += labor;
        laborCharge += labor * laborChargePerHour;
    }
    std::cout << std::endl;
    std::cout << "Estimate for painting " << numRooms << " Rooms:" << std::endl;
    displayEstimate(paintCharge, gallonsNeeded, laborCharge, laborHours);
    return 0;
}

/*
Function: getRooms
Purpose:
    - Gets the number of rooms value as input from the user and validates that the value is not less than 1. 
Parameters:
    - No parameters, this function takes input from the user after outputting a prompt.
Returns:
    - This function returns the rooms value submitted as input by the user.
Preconditions:
    - None
Postconditions:
    - Ensures that the rooms value input by the user is returned.
    - It also ensures that the value is not less than 1 by prompting the user to enter in a new value if it is.
Side Effects: 
    - None
*/
int getRooms(){
    int num_rooms;
    std::cout << "Please enter in the number of rooms: ";
    std::cin >> num_rooms;
    while (num_rooms < 1){
        std::cout << "Invalid rooms option, please try again." << std::endl;
        std::cout << "Please enter in the number of rooms: ";
        std::cin >> num_rooms;
    }
    return num_rooms;
}

/*
Function: getSqFt
Purpose:
    - Gets the SqFt value for a room as input from the user and validates that the value is not negative. 
Parameters:
    - No parameters, this function takes input from the user after outputting a prompt.
Returns:
    - This function returns the SqFt value submitted as input by the user.
Preconditions:
    - None
Postconditions:
    - Ensures that the SqFt value input by the user is returned.
    - It also ensures that the value is not negative by prompting the user to enter in a new value if it is.
Side Effects: 
    - None
*/
float getSqFt(){
    float SqFt;
    std::cout << "Please enter in the square footage for the room: ";
    std::cin >> SqFt;
    while (SqFt < 0){
        std::cout << "Invalid square footage option, please try again." << std::endl;
        std::cout << "Please enter in the square footage for the room: ";
        std::cin >> SqFt;
    }
    return SqFt;
}

/*
Function: gallonsForRoom
Purpose:
    - Calculates the gallons variable by multiplying the SqFt argument by the gallonsPerSqFt global variable and adding 1. 
Parameters:
    - float SqFt: the square footage of a room.
Returns:
    - This function returns gallons variable which is calcualted by multiplying the SqFt argument by the gallonsPerSqFt global variable and adding 1.
Preconditions:
    - None
Postconditions:
    - Ensures that the gallons value is returned.
Side Effects: 
    - None
*/
int gallonsForRoom(float SqFt){
    int gallons = SqFt * gallonsPerSqFt + 1;
    return gallons;
}

/*
Function: getPricePerGallon
Purpose:
    - Gets the price value for a gallon of paint as input from the user and validates that the value is not less than 10. 
Parameters:
    - No parameters, this function takes input from the user after outputting a prompt.
Returns:
    - This function returns the price value submitted as input by the user.
Preconditions:
    - None
Postconditions:
    - Ensures that the price value input by the user is returned.
    - It also ensures that the value is not less than 10 by prompting the user to enter in a new value if it is.
Side Effects: 
    - None
*/
float getPricePerGallon(){
    float price;
    std::cout << "Please enter in the price per gallon of paint: ";
    std::cin >> price;
    while (price < 10){
        std::cout << "Invalid price option, please try again." << std::endl;
        std::cout << "Please enter in the price per gallon of paint: ";
        std::cin >> price;
    }
    return price;
}

/*
Function: displayEstimate
Purpose:
    - Outputs the values for the paint cost, number of gallons of paint, labor cost and labor hours required for the job. 
Parameters:
    - float paint_cost: the cost for the paint needed for the job.
    - int gallons: the number of gallons of paint needed for the job.
    - float labor_cost: the cost for the labor needed for the job.
    - float labor_hours: the number of hours of labor needed for the job.
Returns:
    - This function does not return anything but it does output the argument values alongside descriptive text.
Preconditions:
    - None
Postconditions:
    - Ensures that the argument values are printed with descriptive text.
Side Effects: 
    - None
*/
void displayEstimate(float paint_cost, int gallons, float labor_cost, float labor_hours){
    std::cout << std::fixed << std::showpoint << std::setprecision(2);
    std::cout << "Gallons of paint to purchase: " << gallons << std::endl;
    std::cout << "Number of hours required to paint rooms: " << labor_hours << std::endl;
    std::cout << "Cost of paint: $" << paint_cost << std::endl;
    std::cout << "Cost of labor: $" << labor_cost << std::endl;
    std::cout << "Total cost for job: $" << paint_cost + labor_cost << std::endl;
}