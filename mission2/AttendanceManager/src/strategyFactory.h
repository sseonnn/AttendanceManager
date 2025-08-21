#pragma once
#include <memory>
#include <string>
#include "scoringStrategy.h"

using std::string;
using std::unique_ptr;

class ScoringStrategyFactory {
public:
    unique_ptr<ScoringStrategy> getStrategy(const string& day);

private:
    const string MONDAY = "monday";
    const string TUESDAY = "tuesday";
    const string WEDNESDAY = "wednesday";
    const string THURSDAY = "thursday";
    const string FRIDAY = "friday";
    const string SATURDAY = "saturday";
    const string SUNDAY = "sunday";
};