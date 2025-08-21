#include "scoringStrategy.h"

int RegularDayStrategy::calculateScore() {
    return 1;
}

int WednesdayStrategy::calculateScore(void) {
    return 3;
}

int WeekendStrategy::calculateScore(void) {
    return 2;
}