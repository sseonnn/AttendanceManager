#pragma once
#include <string>

using std::string;

class GradeFactory {
public:
    string getGrade(const int score);

private:
    const string NORMAL_GRADE = "NORMAL";
    const string GOLD_GRADE = "GOLD";
    const string SILVER_GRADE = "SILVER";
};