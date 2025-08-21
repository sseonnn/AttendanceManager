#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct AttendanceStatus {
	string name;
	string attendanceDay;
};

map<string, int> idMap;
int id_cnt = 0;

//dat[사용자ID][요일]
int dayCnt[100][7];
int points[100];
int grade[100];
string names[100];

int wed[100];
int weeken[100];

const string MONDAY = "monday";
const string TUESDAY = "tuesday";
const string WEDNESDAY = "wednesday";
const string THURSDAY = "thursday";
const string FRIDAY = "friday";
const string SATURDAY = "saturday";
const string SUNDAY = "sunday";
const int NORMAL_GRADE = 0;
const int GOLD_GRADE = 1;
const int SILVER_GRADE = 2;

bool isRemovedPlayer(int playerId)
{
	return grade[playerId] != 1 && grade[playerId] != 2 && wed[playerId] == 0 && weeken[playerId] == 0;
}

void printRemovedPlayer()
{
	std::cout << "\n";
	std::cout << "Removed player\n";
	std::cout << "==============\n";
	for (int id = 1; id <= id_cnt; id++) {

		if (isRemovedPlayer(id)) {
			std::cout << names[id] << "\n";
		}
	}
}

void addBonusScore(int playerId)
{
	if (dayCnt[playerId][2] >= 10) {
		points[playerId] += 10;
	}
	if (dayCnt[playerId][5] + dayCnt[playerId][6] >= 10) {
		points[playerId] += 10;
	}
}

void assignGrade(int playerId)
{
	if (points[playerId] >= 50) {
		grade[playerId] = GOLD_GRADE;
	}
	else if (points[playerId] >= 30) {
		grade[playerId] = SILVER_GRADE;
	}
	else {
		grade[playerId] = NORMAL_GRADE;
	}
}

void printResult(int playerId)
{
	cout << "NAME : " << names[playerId] << ", ";
	cout << "POINT : " << points[playerId] << ", ";
	cout << "GRADE : ";

	if (grade[playerId] == GOLD_GRADE) {
		cout << "GOLD" << "\n";
	}
	else if (grade[playerId] == SILVER_GRADE) {
		cout << "SILVER" << "\n";
	}
	else {
		cout << "NORMAL" << "\n";
	}
}

void calculateResults()
{
	for (int id = 1; id <= id_cnt; id++) {
		addBonusScore(id);
		assignGrade(id);
		printResult(id);
	}
}

void addPoints(AttendanceStatus& status, int playerId)
{
	int add_point = 0;
	int index = 0;

	if (status.attendanceDay == MONDAY) {
		index = 0;
		add_point++;
	}
	else if (status.attendanceDay == TUESDAY) {
		index = 1;
		add_point++;
	}
	else if (status.attendanceDay == WEDNESDAY) {
		index = 2;
		add_point += 3;
		wed[playerId] += 1;
	}
	else if (status.attendanceDay == THURSDAY) {
		index = 3;
		add_point++;
	}
	else if (status.attendanceDay == FRIDAY) {
		index = 4;
		add_point++;
	}
	else if (status.attendanceDay == SATURDAY) {
		index = 5;
		add_point += 2;
		weeken[playerId] += 1;
	}
	else if (status.attendanceDay == SUNDAY) {
		index = 6;
		add_point += 2;
		weeken[playerId] += 1;
	}

	//사용자ID별 요일 데이터에 1씩 증가
	dayCnt[playerId][index] += 1;
	points[playerId] += add_point;
}

void assignId(AttendanceStatus& status)
{
	if (idMap.count(status.name) == 0) {
		idMap.insert({ status.name, ++id_cnt });

		if (status.name == "Daisy") {
			int debug = 1;
		}

		names[id_cnt] = status.name;
	}
}

void organizeData(AttendanceStatus status) {
	assignId(status);

	//디버깅용
	if (status.name == "Daisy") {
		int debug = 1;
	}

	addPoints(status, idMap[status.name]);
}

void inputFromFile()
{
	ifstream fin{ "attendance_weekday_500.txt" }; //500개 데이터 입력
	for (int weekday = 0; weekday < 500; weekday++) {
		string name, attendaceDay;
		fin >> name >> attendaceDay;
		organizeData(AttendanceStatus{ name, attendaceDay });
	}
}

void startAttendanceSystem() {
	inputFromFile();
	calculateResults();
	printRemovedPlayer();
}

int main() {
	startAttendanceSystem();
}