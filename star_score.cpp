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

bool isLower(float score, float low_score){
    if (score <= low_score){
        return true;
    }
    else{
        return false;
    }
}

bool isHigher(float score, float high_score){
    if (score >= high_score){
        return true;
    }
    else{
        return false;
    }
}

float calcAverage(float total, int count, float min, float max){
    return ((total - (min + max)) / (count-2));
}