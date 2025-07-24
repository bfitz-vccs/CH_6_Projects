#include <iostream>

void getLengthWidth(float &length, float &width);
float calcPerimeter(float length, float width);
float calcArea(float length, float width);
void displayProperties(float perimeter, float area);

float rectangle_length;
float rectangle_width;

int main(){
    
    getLengthWidth(rectangle_length, rectangle_width);
    displayProperties(rectangle_length, rectangle_width);
    return 0;
}

/* 
Function: getLengthWidth
Purpose:
    - Gets the length and width as input from user, validates measurements in a while loop to 
    make sure that only positive values are submitted.
Parameters:
    - float &length: length of the rectangle passed by reference
    - float &width: width of the rectangle passed by reference
Returns:
    - This function does not return anything (i.e. it's void), although it does assign values to the arguments passed by reference
Preconditions:
    - None
Postconditions:
    - Ensures that the passed by reference length and width arguments are positive and assigned
Side Effects: 
    - None
*/
void getLengthWidth(float &length, float &width){

    std::cout << "Please enter in the length of the rectangle: ";
    std::cin >> length;
    std::cout << "Please enter in the width of the rectangle: ";
    std::cin >> width;

    while (length < 0 || width < 0){
    if (length < 0 && width < 0){
        std::cout << "Invalid length and width measurements, please try again." << std::endl;
        std::cout << "Please enter in the length of the rectangle: ";
        std::cin >> length;
        std::cout << "Please enter in the width of the rectangle: ";
        std::cin >> width;
        }
        else if (length < 0){
        std::cout << "Invalid length measurement, please try again." << std::endl;
        std::cout << "Please enter in the length of the rectangle: ";
        std::cin >> length;
        }
        else if (width < 0){
            std::cout << "Invalid width measurement, please try again." << std::endl;
            std::cout << "Please enter in the width of the rectangle: ";
            std::cin >> width;
        }
    }
}

/*
Function: calcPerimeter
Purpose:
    -Adds double the length to double the width to calculate the rectangle's perimeter
Parameters:
    - float length: length of rectangle
    - float width: width of rectangle
Returns:
    - float: two times the rectangle plus two times the width (i.e. the perimeter)
Preconditions:
    - None
Postconditions:
    - Returns the rectangle perimeter calculation
Side Effects
    - None
*/
float calcPerimeter(float length, float width){
    return 2 * length + 2 * width;
    }


float calcArea(float length, float width){
    return length * width;
}

void displayProperties(float length, float width){

    float perimeter = calcPerimeter(length, width);
    float area = calcArea(length, width);
    std::cout << "The perimeter of the rectangle is: " << perimeter << std::endl;
    std::cout << "The area of the rectangle is: " << area << std::endl;
}