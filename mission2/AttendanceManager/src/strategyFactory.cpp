#include "strategyFactory.h"

unique_ptr<ScoringStrategy> ScoringStrategyFactory::getStrategy(const string& day) {
    if (day == WEDNESDAY) {
        return std::make_unique<WednesdayStrategy>();
    }
    if (day == SATURDAY || day == SUNDAY) {
        return std::make_unique<WeekendStrategy>();
    }
    return std::make_unique<RegularDayStrategy>();
}