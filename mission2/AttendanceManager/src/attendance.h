#pragma once

#include <string>
#include <vector>
#include <map>
#include "scoringStrategy.h"
#include "strategyFactory.h"
#include "gradeFactory.h"

using std::string;
using std::vector;
using std::map;

struct AttendanceStatus {
    string name;
    string attendanceDay;
};

struct Player {
    string name;
    int score = 0;
    int wednesdayCount = 0;
    int weekendCount = 0;
    bool isRemoved = false;
    string grade;
};

class Attendance {
public:
    bool startAttendanceSystem(string fileName);
    bool inputFromFile(string fileName);
    bool addStatus(AttendanceStatus status);
    void calculateResults(void);
    void calculateStatus(void);
    string getName(int playerId);
    int getScore(int playerId);
    bool getisRemoved(int playerId);
    string getPlayerGrade(int playerId);
    
private:
    bool isValidDay(std::string& attendaceDay);
    int calculateScore(string day);
    void updatePlayer(AttendanceStatus status, int score);
    int getId(string name);
    int getBonusScore(int playerId);
    string getGrade(int playerId);
    bool getIsRemoved(int playerId);
    void printResult(void);
    void printStatus(int playerId);
    void printRemovedPlayers();

    vector<AttendanceStatus> records;
    Player players[20];
    map<string, int> idMap;
    int idCnt = 0;
    ScoringStrategyFactory scoreFactory;
    GradeFactory gradeFactory;

    const string MONDAY = "monday";
    const string TUESDAY = "tuesday";
    const string WEDNESDAY = "wednesday";
    const string THURSDAY = "thursday";
    const string FRIDAY = "friday";
    const string SATURDAY = "saturday";
    const string SUNDAY = "sunday";
    const string NORMAL_GRADE = "NORMAL";
    const string GOLD_GRADE = "GOLD";
    const string SILVER_GRADE = "SILVER";
};
