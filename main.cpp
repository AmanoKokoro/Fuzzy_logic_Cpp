#include "main.h"

int main() {
	char c, d, pattern_temp;
	double diff_temp;
	double color = 0, hardness = 0, gravity = 0;
	double patternGravity[3];
	gravityDiff gravitydiff[3];
	FuzzyLogic *flRice = 0, *flMeat = 0;
	FuzzyGravity fg;

	

	for (c = 65; c < 68; c++) {

		flRice = new FuzzyLogic();
		flMeat = new FuzzyLogic();

		std::cout << "パターン：" << c << std:: endl;

		std::cout << "ご飯の盛り度合いを入力してください(0.0 ~ 1.0):";
		std::cin >> color;

		std::cout << "肉の盛り度合いを入力してください(0.0 ~ 1.0):";
		std::cin >> hardness;

		flRice->fuzzyLogic_set(color);
		flMeat->fuzzyLogic_set(hardness);

		fg.fuzzyGavity_compositioin(flRice->gradeArray, flMeat->gradeArray);
		fg.fuzzyGravity_discr(fg.Composition);
		gravity = fg.fuzzyGavity_Calculator();
		std::cout << std::fixed << std::setprecision(3) << "重心：" << gravity << std::endl;

		patternGravity[c - 65] = gravity;

		delete flRice;
		delete flMeat;
	}

	for (c = 0; c < 3; c++) {
		gravitydiff[c].diff	= patternGravity[c] - 0.5;
		gravitydiff[c].pattern = c + 65;
		if (gravitydiff[c].diff < 0) {
			gravitydiff[c].diff = gravitydiff[c].diff * (-1);
		}
	}

	for (c = 0; c < 2; c++) {
		for (d = 2; d > c; d--) {
			if (gravitydiff[d - 1].diff > gravitydiff[d].diff) {
				diff_temp = gravitydiff[d - 1].diff;
				gravitydiff[d - 1].diff = gravitydiff[d].diff;
				gravitydiff[d].diff = diff_temp;

				pattern_temp = gravitydiff[d - 1].pattern;
				gravitydiff[d - 1].pattern = gravitydiff[d].pattern;
				gravitydiff[d].pattern = pattern_temp;
			}
		}
	}

	for (c = 0; c < 3; c++) {
		std::cout << gravitydiff[c].pattern;
	}

	std::cout << "の順で盛り付けが上手です。" <<std::endl;


	return 0;
}
