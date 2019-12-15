#include "FuzzyLogic.h"
#include <cstring>

FuzzyLogic::FuzzyLogic() {
	this->parallelValue = 0;
	this->grade = 0;
	memset(this->gradeArray, 0, sizeof(this->gradeArray));
}

FuzzyLogic::~FuzzyLogic() {

}

void FuzzyLogic::fuzzyLogic_set(double get) {
	this->parallelValue = get;

	gradeArray[0] = fuzzyLogic_ruleOne();
	gradeArray[1] = fuzzyLogic_ruleTwo();
	gradeArray[2] = fuzzyLogic_ruleThree();
}

double FuzzyLogic::fuzzyLogic_ruleOne() {

	if (parallelValue >= 0.5) {
		grade = (2 * parallelValue) - 1.0;
		std::cout << "Rule1(‚·‚²‚­‘½‚¢)_grade:" << grade << std::endl;
		return grade;
	}
	std::cout << "Rule1(‚·‚²‚­‘½‚¢)_grade:" << grade << std::endl;
	return 0;
}

double FuzzyLogic::fuzzyLogic_ruleTwo() {

	if (parallelValue <= 0.5) {
		grade = 2.0 * parallelValue;
		std::cout << "Rule2(‚¿‚å‚¤‚Ç)_grade:" << grade << std::endl;
		return grade;

	}
	else if (parallelValue <= 1.0) {

		grade = ((2 * parallelValue) * (-1) + 2.0);
		std::cout << "Rule2(‚¿‚å‚¤‚Ç)_grade:" << grade << std::endl;
		return grade;
	}
	else {
		std::cout << "Rule2(‚¿‚å‚¤‚Ç)_grade:" << grade << std::endl;
		return 0;
	}
}

double FuzzyLogic::fuzzyLogic_ruleThree() {

	if (parallelValue <= 0.5) {
		grade = -2 * parallelValue + 1;
		std::cout << "Rule3(­‚È‚¢)_grade:" << grade << std::endl;
		return grade;
	}
	std::cout << "Rule3(­‚È‚¢)_grade:" << grade << std::endl;
	return 0;
}
