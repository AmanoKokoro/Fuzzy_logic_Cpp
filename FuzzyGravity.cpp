#include "FuzzyGravity.h"
#include <cstring>

FuzzyGravity::FuzzyGravity() {
	this->result = 0;
	std::memset(this->gradeThirdArray, 0, HORIZONTALAXISNUM);
}

FuzzyGravity::~FuzzyGravity() {

}

void FuzzyGravity::fuzzyGavity_compositioin(double* grade1, double* grade2) {
	int cnt = 0;

	for (; cnt < ARRAYNUM; cnt++) {
		Composition[cnt] = this->fuzzyGravity_OR(cnt, cnt, grade1, grade2);
	}
}


double FuzzyGravity::fuzzyGravity_discr(double* gradeArray) {
	int cnt, gradeCnt;
	//for (gradeCnt = 0; gradeCnt < ARRAYNUM; gradeCnt++) {
	std::cout << "rule1HorizontalNum:";
		for (cnt = 0; cnt < HORIZONTALAXISNUM; cnt++) {
			this->fuzzyGravity_AND(cnt, 0, rule1HorizontalNum, gradeArray);
			std::cout << std::fixed << std::setprecision(2) << rule1HorizontalNum[cnt] << ", ";
		}
		std::cout << std::endl;
	//}

		std::cout << "rule2HorizontalNum:";
	//for (gradeCnt = 0; gradeCnt < ARRAYNUM; gradeCnt++) {
		for (cnt = 0; cnt < HORIZONTALAXISNUM; cnt++) {
			this->fuzzyGravity_AND(cnt, 1, rule2HorizontalNum, gradeArray);
			std::cout << std::fixed << std::setprecision(2) << rule2HorizontalNum[cnt] << ", ";
		}
		std::cout << std::endl;
	//}

		std::cout << "rule3HorizontalNum:";
	//for (gradeCnt = 0; gradeCnt < ARRAYNUM; gradeCnt++) {
		for (cnt = 0; cnt < HORIZONTALAXISNUM; cnt++) {
			this->fuzzyGravity_AND(cnt, 2, rule3HorizontalNum, gradeArray);
			std::cout << std::fixed << std::setprecision(2) << rule3HorizontalNum[cnt] << ", ";
		}
		std::cout << std::endl;
	//}

	return 0;
}



double FuzzyGravity::fuzzyGravity_AND(int i, int j, double* ruleHorizontalArray, double* gradeArray) {

	if (ruleHorizontalArray[i] > gradeArray[j]) {
		ruleHorizontalArray[i] = gradeArray[j];
		return ruleHorizontalArray[i];
	}
	else {
		ruleHorizontalArray[i] = ruleHorizontalArray[i];
		return ruleHorizontalArray[i];
	}

	return 0;
}

double FuzzyGravity::fuzzyGravity_OR(int i, int j, double* ruleHorizontalArray, double* gradeArray) {

	if (ruleHorizontalArray[i] < gradeArray[j]) {
		ruleHorizontalArray[i] = gradeArray[j];
		return ruleHorizontalArray[i];
	}
	else {
		ruleHorizontalArray[i] = ruleHorizontalArray[i];
		return ruleHorizontalArray[i];
	}

	return 0;
}

double FuzzyGravity::fuzzyGavity_Calculator() {
	int i;
	double num = 0.0, den = 0.0;

	for (i = 0; i < HORIZONTALAXISNUM; i++) {
		this->gradeThirdArray[i] = this->fuzzyGravity_OR(i, i, this->rule1HorizontalNum, this->rule2HorizontalNum);
		this->gradeThirdArray[i] = this->fuzzyGravity_OR(i, i, this->rule1HorizontalNum, this->gradeThirdArray);
	}

	for (i = 0; i < HORIZONTALAXISNUM; i++) {
		den += gradeThirdArray[i];
		num = num + this->gradeThirdArray[i] * this->horizontalAxis[i];
	}


	if (den != 0.0) {
		this->result = num / den;
	}
	else {
		this->result = 0;
	}


	return this->result;
}