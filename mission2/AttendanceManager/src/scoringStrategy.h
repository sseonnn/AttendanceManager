#pragma once

#define interface class

interface ScoringStrategy {
public:
    virtual int calculateScore(void) = 0;
    virtual ~ScoringStrategy() = default;
};

class RegularDayStrategy : public ScoringStrategy {
public:
    int calculateScore(void) override;
};

class WednesdayStrategy : public ScoringStrategy {
public:
    int calculateScore(void) override;
};

class WeekendStrategy : public ScoringStrategy {
public:
    int calculateScore(void) override;
};