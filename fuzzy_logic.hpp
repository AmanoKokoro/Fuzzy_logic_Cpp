#ifndef FUZZY_LOGIC
#define FUZZY_LOGIC

#include <iostream>
#include <cmath>

#define ARRAYNUM 3

class FuzzyLogic {
public:
    FuzzyLogic();
    ~FuzzyLogic();

public:
    double gradeArray[ARRAYNUM];

    void fuzzyLogic_set(double);

private:
    double grade;
    double parallelValue;

    double fuzzyLogic_ruleOne();
    double fuzzyLogic_ruleTwo();
    double fuzzyLogic_ruleThree();
};

#endif //FUZZY_LOGIC
