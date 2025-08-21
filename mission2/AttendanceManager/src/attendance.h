#pragma once

#include <string>

using namespace std;

struct AttendanceStatus {
	string name;
	string attendanceDay;
};

bool isRemovedPlayer(int playerId);
bool isBonusScore(int playerId);
void addBonusScore(int playerId);
void assignGrade(int playerId);
void printResult(int playerId);
void calculateResults();
void addPoints(AttendanceStatus& status, int playerId);
void assignId(AttendanceStatus& status);
void organizeData(AttendanceStatus status);
void inputFromFile();
void startAttendanceSystem();
