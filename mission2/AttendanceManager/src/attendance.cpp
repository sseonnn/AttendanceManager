#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "attendance.h"

using std::string;
using std::cout;
using std::ifstream;

bool Attendance::startAttendanceSystem(string fileName) {
	if (inputFromFile(fileName) == false) return false;
	calculateStatus();
	calculateResults();
	printResult();
	return true;
}

bool Attendance::inputFromFile(string fileName) {
	ifstream fin{ fileName }; //500개 데이터 입력
	for (int weekday = 0; weekday < 500; weekday++) {
		string name, attendanceDay;
		fin >> name >> attendanceDay;
		if (addStatus(AttendanceStatus{ name, attendanceDay }) == false) {
			return false;
		}
	}
	return true;
}

bool Attendance::addStatus(AttendanceStatus status) {
	if (isValidDay(status.attendanceDay) == false) {
		return false;
	}
	records.push_back(status);
	return true;
}

bool Attendance::isValidDay(string& attendaceDay) {
	return (attendaceDay == MONDAY) || (attendaceDay == TUESDAY) || (attendaceDay == WEDNESDAY) || (attendaceDay == THURSDAY) || 
		   (attendaceDay == FRIDAY) || (attendaceDay == SATURDAY || (attendaceDay == SUNDAY));
}

void Attendance::calculateStatus() {
	for (const auto& status : records) {
		updatePlayer(status, calculateScore(status.attendanceDay));
	}
}

int Attendance::calculateScore(string day) {
	auto strategy = factory.getStrategy(day);
	return strategy->calculateScore();
}

void Attendance::updatePlayer(AttendanceStatus status, int score) {
	auto& player = players[getId(status.name)];
	player.name = status.name;
	player.score += score;
	if (status.attendanceDay == WEDNESDAY) player.wednesdayCount++;
	if (status.attendanceDay == SATURDAY || status.attendanceDay == SUNDAY) player.weekendCount++;
}

int Attendance::getId(string name) {
	if (idMap.count(name) == 0) {
		idMap.insert({ name, ++idCnt });
	}
	return idMap[name];
}

void Attendance::calculateResults(void) {
	for (int id = 1; id <= idCnt; id++) {
		players[id].score += getBonusScore(id);
		players[id].grade = getGrade(id);
		players[id].isRemoved = getIsRemoved(id);
	}
}

int Attendance::getBonusScore(int playerId) {
	int bonusScore = 0;

	if (players[playerId].wednesdayCount >= 10) {
		bonusScore += 10;
	}

	if (players[playerId].weekendCount >= 10) {
		bonusScore += 10;
	}

	return bonusScore;
}

string Attendance::getGrade(int playerId) {
	if (players[playerId].score >= 50) return GOLD_GRADE;
	if (players[playerId].score >= 30) return SILVER_GRADE;
	return NORMAL_GRADE;
}

bool Attendance::getIsRemoved(int playerId) {
	return (players[playerId].grade == NORMAL_GRADE) && (players[playerId].wednesdayCount == 0) && (players[playerId].weekendCount == 0);
}

void Attendance::printResult(void)
{
	for (int id = 1; id <= idCnt; id++) {
		printStatus(id);
	}
	printRemovedPlayers();
}

void Attendance::printStatus(int playerId) {
	cout << "NAME : " << players[playerId].name << ", ";
	cout << "POINT : " << players[playerId].score << ", ";
	cout << "GRADE : " << players[playerId].grade << "\n";
}

void Attendance::printRemovedPlayers() {
	cout << "\n";
	cout << "Removed player\n";
	cout << "==============\n";
	for (int id = 1; id <= idCnt; id++) {
		if (players[id].isRemoved) {
			cout << players[id].name << "\n";
		}
	}
}

string Attendance::getName(int playerId) { return players[playerId].name; }
int Attendance::getScore(int playerId) { return players[playerId].score; }
bool Attendance::getisRemoved(int playerId) { return players[playerId].isRemoved; }
string Attendance::getPlayerGrade(int playerId) { return players[playerId].grade; }
