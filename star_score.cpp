/*
This program takes the scores from five judges and drops the lowest and highest scores.
The average of the remaining three scores is calculated and output with descriptive text.
*/
#include <iostream>

float getScore();
bool isLower(float score, float low_score);
bool isHigher(float score, float high_score);
float calcAverage(float total, int count, float min, float max);

float score_total = 0;
int score_count = 0;
float minScore;
float maxScore;

int main(){
    float current_score = getScore();
    minScore = current_score;
    maxScore = current_score;
    score_total += current_score;
    score_count ++;
    for (int i = 1; i < 5; i++){
        current_score = getScore();
        score_total += current_score;
        score_count ++;
        if (isLower(current_score, minScore)){
            minScore = current_score;
        }
        if (isHigher(current_score, maxScore)){
            maxScore = current_score;
        }
    }

    float average = calcAverage(score_total, score_count, minScore, maxScore);
    std::cout << "The score is: " << average << std::endl;

    return 0;
}

/*
Function: getScore
Purpose:
    - Gets the score value as input from the user and returns this value.
    - Uses a while loop to validate that the score value is not less than 0 or greater than 1, prompts the user for new input if so.

Parameters:
    - No parameters, this function takes input from the user after outputting a prompt.
Returns:
    - This function returns the score value submitted as input by the user.
Preconditions:
    - None
Postconditions:
    - Ensures that the input variable is not less than 0 or greater than 10 and then returns this value.
Side Effects: 
    - None
*/
float getScore(){
    float score;
    std::cout << "Please enter in a score from 0 - 10: ";
    std::cin >> score;
    while (score < 0.0 || score > 10.0){
        std::cout << "Invalid option, please enter in a score from 0 - 10";
        std::cin >> score;
        }

    return score;
    }

    /*
Function: isLower
Purpose:
    - Returns true or false depending on if the score argument is less than or equal to the low_score argument. 
Parameters:
    - float score: the score from a judge.
    - float low_score: the current lowest score from any of the judges.
Returns:
    - This function returns true if the score argument is less than or equal to the low_score argument, and false if not.
Preconditions:
    - None
Postconditions:
    - Ensures that either true or false is returned.
Side Effects: 
    - None
*/
bool isLower(float score, float low_score){
    if (score <= low_score){
        return true;
    }
    else{
        return false;
    }
}

/*
Function: isHigher
Purpose:
    - Returns true or false depending on if the score argument is greater than or equal to the high_score argument. 
Parameters:
    - float score: the score from a judge.
    - float high_score: the current highest score from any of the judges.
Returns:
    - This function returns true if the score argument is greater than or equal to the high_score argument, and false if not.
Preconditions:
    - None
Postconditions:
    - Ensures that either true or false is returned.
Side Effects: 
    - None
*/
bool isHigher(float score, float high_score){
    if (score >= high_score){
        return true;
    }
    else{
        return false;
    }
}

    /*
Function: calcAverage
Purpose:
    - Calculates the average score after dropping the highest and lowest scores from the judges. 
Parameters:
    - float total: the sum of all the previously input scores.
    - int count: the number of times a score from a judge has been input.
    - float min: the lowest score input from a judge.
    - float max: the highest score input from a judge.
Returns:
    - This function takes the total score and subtracts the min and max score values.
    It then reduces count by 2, and returns the quotient of total divided by count.
Preconditions:
    - None
Postconditions:
    - Ensures that the calculated value is returned.
Side Effects: 
    - None
*/
float calcAverage(float total, int count, float min, float max){
    return ((total - (min + max)) / (count-2));
}