#include "fuzzy_gravity.hpp"
#include <cstring>

FuzzyGravity::FuzzyGravity() {
	this->result = 0;

	std::memset(this->gradeThirdArray, 0, HORIZONTALAXISNUM);
}

FuzzyGravity::~FuzzyGravity(){

}


double FuzzyGravity::fuzzyGravity_discr(double* gradeArray) {
	int cnt, gradeCnt;
	for(gradeCnt = 0; gradeCnt < ARRAYNUM; gradeCnt++){
    	for(cnt = 0; cnt < HORIZONTALAXISNUM; cnt++) {
            this->fuzzyGravity_AND(cnt, gradeCnt, rule1HorizontalNum, gradeArray);
        }
    }

	for(gradeCnt = 0; gradeCnt < ARRAYNUM; gradeCnt++){
    	for(cnt = 0; cnt < HORIZONTALAXISNUM; cnt++) {
            this->fuzzyGravity_AND(cnt, gradeCnt, rule2HorizontalNum, gradeArray);
        }
    }

	for(gradeCnt = 0; gradeCnt < ARRAYNUM; gradeCnt++){
    	for(cnt = 0; cnt < HORIZONTALAXISNUM; cnt++) {
            this->fuzzyGravity_AND(cnt, gradeCnt, rule3HorizontalNum, gradeArray);
        }
    }

	return 0;
}

double FuzzyGravity::fuzzyGravity_AND(int i, int j, double* ruleHorizontalArray, double* gradeArray) {

	if(ruleHorizontalArray[i] > gradeArray[j]){
		ruleHorizontalArray[i] = gradeArray[j];
		return ruleHorizontalArray[i];
	}else {
		ruleHorizontalArray[i] = ruleHorizontalArray[i];
		return ruleHorizontalArray[i];
	}

	return 0;
}

double FuzzyGravity::fuzzyGravity_OR(int i, int j, double* ruleHorizontalArray, double* gradeArray) {

	if(ruleHorizontalArray[i] < gradeArray[j]){
		ruleHorizontalArray[i] = gradeArray[j];
		return ruleHorizontalArray[i];
	}else {
		ruleHorizontalArray[i] = ruleHorizontalArray[i];
		return ruleHorizontalArray[i];
	}

	return 0;
}

double FuzzyGravity::fuzzyGavity_Calculator() {
	int i;
	double num = 0.0, den = 0.0;

	for(i = 0; i <= HORIZONTALAXISNUM; i++) {
		this->gradeThirdArray[i] = this->fuzzyGravity_OR(i, i, this->rule1HorizontalNum, this->rule2HorizontalNum);
		this->gradeThirdArray[i] = this->fuzzyGravity_OR(i, i, this->rule1HorizontalNum, this->gradeThirdArray);
	}

	for(i = 0; i < HORIZONTALAXISNUM; i++) {
		num = num + this->gradeThirdArray[i] * this->horizontalAxis[i];
		den = den + gradeThirdArray[i];
	}

	if(den != 0.0) {
		this->result = num / den;
	}else{
		this->result = 0;
	}


	return this->result;
}