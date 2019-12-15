#ifndef FUZZY_GRAVITY
#define FUZZY_GRAVITY

#include <iostream>
#include <cmath>

#define ARRAYNUM 3
#define HORIZONTALAXISNUM 11

class FuzzyGravity {
public:
	FuzzyGravity();
	~FuzzyGravity();

public:
	double result;


	double fuzzyGravity_init(double*, double*);
	double fuzzyGravity_discr(double*);
	double fuzzyGavity_Calculator();

private:

	double horizontalAxis[HORIZONTALAXISNUM] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
	double rule1HorizontalNum[HORIZONTALAXISNUM] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.4, 0.6, 0.8, 1.0};
	double rule2HorizontalNum[HORIZONTALAXISNUM] = {0.0, 0.2, 0.4, 0.6, 0.8, 1.0, 0.8, 0.6, 0.4, 0.2, 0.0};
	double rule3HorizontalNum[HORIZONTALAXISNUM] = {1.0, 0.8, 0.6, 0.4, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
	double gradeThirdArray[HORIZONTALAXISNUM];

	double fuzzyGravity_AND(int, int, double*, double*);
	double fuzzyGravity_OR(int, int, double*, double*);
};

#endif //FUZZY_GRAVITY
