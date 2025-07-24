#include <iostream>
#include <iomanip>
#include <cmath>

int getRooms();
float getSqFt();
int gallonsForRoom(float SqFt);
float getPricePerGallon();
void displayEstimate(float paint_cost, float gallons, float labor_cost, float labor_hours);

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

int gallonsForRoom(float SqFt){
    int gallons = SqFt * gallonsPerSqFt + 1;
    return gallons;
}

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

void displayEstimate(float paint_cost, float gallons, float labor_cost, float labor_hours){
    std::cout << "Gallons of paint to purchase: " << gallons << std::endl;
    std::cout << std::fixed << std::showpoint << std::setprecision(2);
    std::cout << "Number of hours required to paint rooms: " << labor_hours << std::endl;
    std::cout << "Cost of paint: $" << paint_cost << std::endl;
    std::cout << "Cost of labor: $" << labor_cost << std::endl;
    std::cout << "Total cost for job: $" << paint_cost + labor_cost << std::endl;
}