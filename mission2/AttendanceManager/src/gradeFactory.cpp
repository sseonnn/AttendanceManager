#include "gradeFactory.h"

string GradeFactory::getGrade(const int score) {
	if (score >= 50) return GOLD_GRADE;
	if (score >= 30) return SILVER_GRADE;
	return NORMAL_GRADE;
}