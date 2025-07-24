/*
This program prompts the user to enter in the length and width measurements of a rectangle.
The program then outputs the perimeter and area of the rectangle based on the measurement inputs.
*/

#include <iostream>

void getLengthWidth(float &length, float &width);
float calcPerimeter(float length, float width);
float calcArea(float length, float width);
void displayProperties(float perimeter, float area);

float rectangle_length;
float rectangle_width;

int main(){
    
    getLengthWidth(rectangle_length, rectangle_width);
    float rectangle_perimeter = calcPerimeter(rectangle_length, rectangle_width);
    float rectangle_area = calcArea(rectangle_length, rectangle_width);
    displayProperties(rectangle_perimeter, rectangle_area);
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
    -Gets the length and width as arguments, adds double the length to double the width to 
    calculate the rectangle's perimeter
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

/*
Function: calcArea
Purpose:
    - Gets the length and width as arguments and returns their product
Parameters:
    - float length: length of rectangle
    - float width: width of rectangle
Returns:
    - This function returns the product of length and width
Preconditions:
    - None
Postconditions:
    - Returns the rectangle area calculation
Side Effects:
    - None
*/
float calcArea(float length, float width){
    return length * width;
}

/*
Function: displayProperties
Purpose:
    - Displays the perimeter and area alongside descriptive textual output
Parameters:
    - float perimeter: perimeter of the rectangle
    - float area: area of the rectangle
Returns:
    - Does not return any value, but prints output
Preconditions:
    - None
Postconditions:
    - Outputs the perimeter and area of the rectangle with descriptive textual output
Side Effects:
    - None
*/
void displayProperties(float perimeter, float area){

    std::cout << "The perimeter of the rectangle is: " << perimeter << std::endl;
    std::cout << "The area of the rectangle is: " << area << std::endl;
}